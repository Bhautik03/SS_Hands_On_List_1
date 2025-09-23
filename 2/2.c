/*
============================================================================
Name : 2.c
Author : Bhautik Vekariya
Description : Write a simple program to execute in an infinite loop at the 
	      background. Go to /proc directory and identify all the process 
	      related information in the corresponding proc directory.
Date: 7 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main() {
    while(1) {       
        printf("Running in background!!!\n");
        sleep(3);               
    }
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/MT2025029/2$ gcc 2.c
bhautik@bhautik:~/SS/MT2025029/2$ ./a.out &
[1] 9967
bhautik@bhautik:~/SS/MT2025029/2$ Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
Running in background!!!
bhautik@bhautik:~/SS/MT2025029/2$ cd /proc/9967
bhautik@bhautik:/proc/9967$ ls
arch_status         fdinfo             ns             smaps_rollup
attr                gid_map            numa_maps      stack
autogroup           io                 oom_adj        stat
auxv                ksm_merging_pages  oom_score      statm
cgroup              ksm_stat           oom_score_adj  status
clear_refs          latency            pagemap        syscall
cmdline             limits             patch_state    task
comm                loginuid           personality    timens_offsets
coredump_filter     map_files          projid_map     timers
cpu_resctrl_groups  maps               root           timerslack_ns
cpuset              mem                sched          uid_map
cwd                 mountinfo          schedstat      wchan
environ             mounts             sessionid
exe                 mountstats         setgroups
fd                  net                smaps
============================================================================
*/
