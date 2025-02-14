#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <PID> <Number>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);  // Target process ID
    int message = atoi(argv[2]);  // Message to send

    union sigval value;
    value.sival_int = message;

    sigqueue(pid, SIGUSR1, value);  // Send SIGUSR1 with data
    printf("📤 Sent SIGUSR1 with number: %d to PID: %d\n", message, pid);
    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// // Signal handler function
// void handle_signal(int sig) {
//     if (sig == SIGINT)  // Ctrl+C signal
//         printf("\nCaught SIGINT! But I'm not quitting!\n");
// }

// int main() {
//     signal(SIGINT, handle_signal); // Set signal handler

//     printf("PID: %d\n", getpid());
//     printf("Try pressing Ctrl+C!\n");

//     while (1) sleep(1);  // Keep running
// }





// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// // Signal handler function
// void handle_signal(int sig, siginfo_t *info, void *context) {
//     printf("\nCaught signal %d from process %d\n", sig, info->si_pid);
// }

// int main() {
//     struct sigaction sa;
//     sa.sa_sigaction = handle_signal;
//     // sa.sa_flags = SA_SIGINFO; // Enable additional info

//     sigaction(SIGUSR1, &sa, NULL); // Handle SIGUSR1

//     printf("PID: %d\n", getpid());
//     printf("Send SIGUSR1 using: kill -SIGUSR1 %d\n", getpid());

//     while (1) sleep(1);  // Keep running
// }
