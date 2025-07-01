#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

/**
 @brief Signal handlers for shutdown.
 
 To set up handlers for signals like SIGINT and SIGTERM,
 so that the program can clean up memory, restore terminal settings,
 and exit when interrupted.
*/
void setup_signal_handlers();

/**
 @brief Cleanup on receiving a termination signal.
 
 Called automatically when a registered signal (like Ctrl+C) is received.
 Should free memory, close audio resources, restore cursor visibility, etc.
 
 @param signum Signal Number.
*/
void handle_signal(int signum);

#endif