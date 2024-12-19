#ifndef UTIL_H
#define UTIL_H

#define PV_NOTICE 5
#define PV_INFO 6

// Print messages depending on verbosity level
void printv(int message_verbose_level, const char *format, ...);

// Spin until the specified number of microseconds has elapsed
void spin_microseconds(long microseconds);

// Write a line of text to a file
void echo(const char *filename, const char *format, ...);

#endif // UTIL_H
