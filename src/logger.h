#ifndef __TINC_LOGGER_H__

typedef enum debug_t {
	DEBUG_NOTHING = 0,			/* Quiet mode, only show starting/stopping of the daemon */
	DEBUG_ALWAYS = 0,
	DEBUG_CONNECTIONS = 1,		/* Show (dis)connects of other tinc daemons via TCP */
	DEBUG_ERROR = 2,			/* Show error messages received from other hosts */
	DEBUG_STATUS = 2,			/* Show status messages received from other hosts */
	DEBUG_PROTOCOL = 3,			/* Show the requests that are sent/received */
	DEBUG_META = 4,				/* Show contents of every request that is sent/received */
	DEBUG_TRAFFIC = 5,			/* Show network traffic information */
	DEBUG_PACKET = 6,			/* Show contents of each packet that is being sent/received */
	DEBUG_SCARY_THINGS = 10		/* You have been warned */
} debug_t;

typedef enum logmode_t {
	LOGMODE_NULL,
	LOGMODE_STDERR,
	LOGMODE_FILE,
	LOGMODE_SYSLOG
} logmode_t;

#ifndef HAVE_SYSLOG
enum {
	LOG_EMERG,
	LOG_ALERT,
	LOG_CRIT,
	LOG_ERR,
	LOG_WARNING,
	LOG_NOTICE,
	LOG_INFO,
	LOG_DEBUG,
};
#endif

extern debug_t debug_level;
extern void openlogger(const char *, logmode_t);
extern void logger(int, const char *, ...) __attribute__ ((format(printf, 2, 3)));
extern void closelogger(void);

#define ifdebug(l) if(debug_level >= DEBUG_##l)

#endif /* __TINC_LOGGER_H__ */
