if [ "${1}" = "-4" -o "${1}" = "-6" ]
then
  vers=${1}
  shift
else
  vers="-6"
fi
host=${1-0}
port=${2-443}
args=""
if [ $# -gt 2 ]
then
  shift; shift
  args="$@"
fi
exec HOME/command/sslclient -RHl0 "$vers" $args -- "$host" "$port" TCPBIN/mconnect-io
