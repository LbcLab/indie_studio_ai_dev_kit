#!/bin/sh

# 1 - pull indie_share
# 2 - place assets in repo
# 3 - make project
# 4 - create tarball with assets & binary
# 5 - push tarball

verbose=false
upload=false

gtfo()
{
  echo -e "\033[1;49;41m$1\033[0m" >&2
  exit "${2:-1}"
}

success()
{
  echo -e "\033[1;49;42m$1\033[0m" >&2
}

notice()
{
  #if $verbose ; then echo -e "\033[38;5;44m$1\033[0m" >&2 ; fi
  echo -e "\033[38;5;44m$1\033[0m" >&2
}

get_repository()
{
  if $verbose ; then
    git clone --progress $1
  else
    git clone $1
  fi
}

is_up_to_date()
{
  [ $(git rev-parse HEAD) = $(git ls-remote $(git rev-parse --abbrev-ref @{u} |\
    sed 's/\// /g') | cut -f1) ] && return 0 || return 1
}

#if is_up_to_date ; then up_to_date=true ; else up_to_date=false ; fi

get_last_revision()
{
  if [ $verbose ]; then
    git pull -v $1 master
  else
    git pull $1 master
  fi
}

usage()
{
  printf 'Usage: %s [-hvu]\n' "$(basename "$0")" >&2
  printf 'Indie studio build system.\n\n'
  printf '\t-h\t--help\t\tDisplay this help\n'
  printf '\t-v\t--verbose\tExplain what is being done\n'
  printf '\t-u\t--upload\tUpload tarball to LbcLab\n\t\t\t\t(note: only LbcLab sysadmin is allowed to\n\t\t\t\tperform such operation)\n'
}

OPTS=`getopt -o hvu --long help,verbose,upload \
       -n $0 -- "$@"`

if [ $? != 0 ] ; then echo "Terminating..." >&2 ; exit 1 ; fi

eval set -- "$OPTS"

while true ; do
  case "$1" in
    -h|--help) usage ; exit 64 ;;
    -v|--verbose) verbose=true ; shift ;;
    -u|--upload) upload=true ; shift ;;
    --) shift ; break ;;
    *) echo "Internal error !" ; exit 1 ;;
  esac
done

notice "Pull last master version from AI dev kit"
get_last_revision "git@github.com:LbcLab/indie_studio_ai_dev_kit.git"
if [ $? -ne 0 ]; then gtfo "Cannot pull AI dev kit" ; fi

notice "Call make"
make -j `nproc` || gtfo "make failed"
doxygen Doxyfile || gtfo "documentation failed"

success "Project build !"

spinner() {
  local i sp n
  sp='/-\|'
  n=${#sp}
  while sleep 0.1; do
    printf "%s\b" "${sp:i++%n:1}"
  done
}

make_tarball()
{
  if $verbose ; then
    tar cvzf $1 doc Doxyfile inc lua Makefile README.md srcs
  else
    spinner &
    spinner_pid=$!
    tar czf $1 doc Doxyfile inc lua Makefile README.md srcs
    kill $spinner_pid &>/dev/null
    printf '\n'
  fi
}

if $upload ; then
  #date=`date +%d-%m-%Y-%H%M`
  date=`date +%d-%m-%Y`
  tarball="AIDEVKIT-$date.tar.gz"
  notice "Create Tarball"
  make_tarball $tarball
  notice "Upload Tarball"
  scp -P 4242 $tarball valkheim@lbclab.com:/var/www/html/gauntlet/install/NG-AI-devkit.tar.gz
  exit 0
else
  notice "Consider uploading build to public LbcLab plateform using 'upload' option."
  exit 0
fi

exit 0
