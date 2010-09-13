#ifndef garnet_galloc_h
#define garnet_galloc_h


void* g_malloc(size_t size);
void* g_malloc2(size_t _N, size_t size);


#define     g_new(_type_, _N)   (_type_ *)g_malloc2( _N, sizeof(_type_) )


void g_free(void* _P);


#endif  /* garnet_galloc_h */
