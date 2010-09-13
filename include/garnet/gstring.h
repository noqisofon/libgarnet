#ifndef garnet_gstring_h
#define garnet_gstring_h


char*           g_strdup(const char* self);


char*           g_strndup(const char* self, size_t _N);


char*           g_strnfill(size_t _N, char filled_ch);


const char*     g_strfind(const char* self, char found_ch);


char*           g_str_rfind(const char* self, size_t _N, char found_ch);


bool            g_str_startwith(const char* self, const char* prefix);


char*           g_str_concat(char* self, char* right);


#endif  /* garnet_gstring_h */
