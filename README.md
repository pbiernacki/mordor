mordor for freebsd
==================

    root@fafik:~kaktus/kodzik/mordor # make load
    /sbin/kldload -v /home/kaktus/kodzik/mordor/mordor.ko
    Mordor loaded
    Loaded /home/kaktus/kodzik/mordor/mordor.ko, id=34
    root@fafik:~kaktus/kodzik/mordor # ls -l /dev/mordor
    cr--r--r--  1 root  wheel  0x92 Mar 28 02:15 /dev/mordor
    root@fafik:~kaktus/kodzik/mordor # cat /dev/mordor
    one does not simply read from mordor
    root@fafik:~kaktus/kodzik/mordor #

