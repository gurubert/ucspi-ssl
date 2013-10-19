if [ "${1}" = "-4" -o "${1}" = "-6" ]
then
  vers=${1}
  shift
else
  vers="-6"
fi
host=${1-0}
path=${2-}
port=${3-443}
args=""
if [ $# -gt 3 ]
then
  shift; shift; shift
  args="$@"
fi
echo "GET /$path HTTP/1.0
Host: $host:$port
" | HOME/command/sslclient -XRHl0 "$vers" $args -- "$host" "$port" sh -c '
  TCPBIN/addcr >&7
  exec TCPBIN/delcr <&6
' | awk '/^$/ { body=1; next } { if (body) print }'
