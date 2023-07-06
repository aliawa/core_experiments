#include <sys/prctl.h>   // prctl


    // core dump
    s_dumpCore = load_check_ex(MAND_CONF, "core-dump", 0);
    if (s_dumpCore) {
        // Dumpable 
        int ret;

        /* Get the Dumpable state */
        ret = prctl( PR_GET_DUMPABLE, 0, 0, 0, 0 );
        MAND_LOG(DBG_INFO,  "PR_GET_DUMPABLE returned %d", ret );

        /* Set the Dumpable state to be enabled */
        ret = prctl( PR_SET_DUMPABLE, 1, 0, 0, 0 );
        MAND_LOG(DBG_INFO,  "PR_SET_DUMPABLE returned %d", ret );

        /* Get the Dumpable state again, make sure it was set */
        ret = prctl( PR_GET_DUMPABLE, 0, 0, 0, 0 );
        MAND_LOG(DBG_INFO,  "PR_GET_DUMPABLE returned %d", ret );


        struct rlimit rlim;

        /* Get the core dump limitation */
        ret = getrlimit(RLIMIT_CORE, &rlim);
        MAND_LOG(DBG_INFO,  "RLIMIT_CORE returned %d (%d, %d)", ret, rlim.rlim_cur, rlim.rlim_max );

        /* Set the core dump limitation to be unlimited */
        rlim.rlim_cur = RLIM_INFINITY;
        rlim.rlim_max = RLIM_INFINITY;
        ret = setrlimit(RLIMIT_CORE, &rlim);
        MAND_LOG(DBG_INFO,  "RLIMIT_CORE returned %d", ret );

        /* Get the core dump limitation again */
        ret = getrlimit(RLIMIT_CORE, &rlim);
        MAND_LOG(DBG_INFO,  "RLIMIT_CORE returned %d (%d, %d)", ret, rlim.rlim_cur, rlim.rlim_max );
    }
