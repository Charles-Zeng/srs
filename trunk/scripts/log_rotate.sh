#!/bin/sh

log_path='/home/charles/srs/logs'
log_file_name='srs.log'
pid_file='/home/charles/srs/objs/srs.pid'

log_suffix=`date -d yesterday +%Y%m%d`
log_file=${log_path}/${log_file_name}
back_log_file=${log_path}/${log_file_name}.${log_suffix}
mv ${log_file} ${back_log_file}

pid=`cat ${pid_file}`
#repoen srs log file
kill -USR1 ${pid}

# compress log
gzip ${back_log_file}
