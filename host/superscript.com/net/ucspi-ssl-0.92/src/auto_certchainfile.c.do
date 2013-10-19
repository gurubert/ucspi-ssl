dependon auto-str conf-certchainfile
formake './auto-str auto_certchainfile "`head -1 conf-certchainfile`" > auto_certchainfile.c'
./auto-str auto_certchainfile "`head -1 conf-certchainfile`"
