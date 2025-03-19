#define LENGHT_USER_TEXT 500

#ifdef _WIN32
    #define CHAT_HISTORY_PATH "chat_history\\chat_history.txt"
#else
    #define CHAT_HISTORY_PATH "chat_history/chat_history.txt"
#endif