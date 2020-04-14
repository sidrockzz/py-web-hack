node default {
     class { 'ntp':
   servers => ['nist-time-server.eoni.com','nist1-lv.ustiming.org','ntp-nist.ldsbc.edu']
   }
}
