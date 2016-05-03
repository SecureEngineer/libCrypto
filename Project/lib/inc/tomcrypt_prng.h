/* ---- PRNG Stuff ---- */
#ifdef LTC_YARROW
struct yarrow_prng {
    int                   cipher, hash;
    unsigned char         pool[MAXBLOCKSIZE];
    symmetric_CTR         ctr;
    LTC_MUTEX_TYPE(prng_lock)
};
#endif

#ifdef LTC_RC4
struct rc4_prng {
    int x, y;
    unsigned char buf[256];
};
#endif

#ifdef LTC_FORTUNA
struct fortuna_prng {
    hash_state pool[LTC_FORTUNA_POOLS];     /* the  pools */

    symmetric_key skey;

    unsigned char K[32],      /* the current key */
                  IV[16];     /* IV for CTR mode */
    
    unsigned long pool_idx,   /* current pool we will add to */
                  pool0_len,  /* length of 0'th pool */
                  wd;            

    ulong64       reset_cnt;  /* number of times we have reset */
    LTC_MUTEX_TYPE(prng_lock)
};
#endif

#ifdef LTC_SOBER128
struct sober128_prng {
    ulong32      R[17],          /* Working storage for the shift register */
                 initR[17],      /* saved register contents */ 
                 konst,          /* key dependent constant */
                 sbuf;           /* partial word encryption buffer */

    int          nbuf,           /* number of part-word stream bits buffered */
                 flag,           /* first add_entropy call or not? */
                 set;            /* did we call add_entropy to set key? */
    
};
#endif

typedef union Prng_state {
    char dummy[1];
#ifdef LTC_YARROW
    struct yarrow_prng    yarrow;
#endif
#ifdef LTC_RC4
    struct rc4_prng       rc4;
#endif
#ifdef LTC_FORTUNA
    struct fortuna_prng   fortuna;
#endif
#ifdef LTC_SOBER128
    struct sober128_prng  sober128;
#endif
} prng_state;

/** PRNG descriptor */
extern struct ltc_prng_descriptor {
    /** Name of the PRNG */
    char *name;
    /** size in bytes of exported state */
    int  export_size;
    /** Start a PRNG state
        @param prng   [out] The state to initialize
        @return CRYPT_OK if successful
    */
    int (*start)(prng_state *prng);
    /** Add entropy to the PRNG
        @param in         The entropy
        @param inlen      Length of the entropy (octets)\
        @param prng       The PRNG state
        @return CRYPT_OK if successful
    */
    int (*add_entropy)(const unsigned char *in, unsigned long inlen, prng_state *prng);
    /** Ready a PRNG state to read from
        @param prng       The PRNG state to ready
        @return CRYPT_OK if successful
    */
    int (*ready)(prng_state *prng);
    /** Read from the PRNG
        @param out     [out] Where to store the data
        @param outlen  Length of data desired (octets)
        @param prng    The PRNG state to read from
        @return Number of octets read
    */
    unsigned long (*read)(unsigned char *out, unsigned long outlen, prng_state *prng);
    /** Terminate a PRNG state
        @param prng   The PRNG state to terminate
        @return CRYPT_OK if successful
    */
    int (*done)(prng_state *prng);
    /** Export a PRNG state  
        @param out     [out] The destination for the state
        @param outlen  [in/out] The max size and resulting size of the PRNG state
        @param prng    The PRNG to export
        @return CRYPT_OK if successful
    */
    int (*pexport)(unsigned char *out, unsigned long *outlen, prng_state *prng);
    /** Import a PRNG state
        @param in      The data to import
        @param inlen   The length of the data to import (octets)
        @param prng    The PRNG to initialize/import
        @return CRYPT_OK if successful
    */
    int (*pimport)(const unsigned char *in, unsigned long inlen, prng_state *prng);
    /** Self-test the PRNG
        @return CRYPT_OK if successful, CRYPT_NOP if self-testing has been disabled
    */
    int (*test)(void);
} prng_descriptor[];

#ifdef LTC_YARROW
DLLEXPORT int yarrow_start(prng_state *prng);
DLLEXPORT int yarrow_add_entropy(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int yarrow_ready(prng_state *prng);
DLLEXPORT unsigned long yarrow_read(unsigned char *out, unsigned long outlen, prng_state *prng);
DLLEXPORT int yarrow_done(prng_state *prng);
DLLEXPORT int  yarrow_export(unsigned char *out, unsigned long *outlen, prng_state *prng);
DLLEXPORT int  yarrow_import(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int  yarrow_test(void);
extern const struct ltc_prng_descriptor yarrow_desc;
#endif

#ifdef LTC_FORTUNA
DLLEXPORT int fortuna_start(prng_state *prng);
DLLEXPORT int fortuna_add_entropy(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int fortuna_ready(prng_state *prng);
DLLEXPORT unsigned long fortuna_read(unsigned char *out, unsigned long outlen, prng_state *prng);
DLLEXPORT int fortuna_done(prng_state *prng);
DLLEXPORT int  fortuna_export(unsigned char *out, unsigned long *outlen, prng_state *prng);
DLLEXPORT int  fortuna_import(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int  fortuna_test(void);
extern const struct ltc_prng_descriptor fortuna_desc;
#endif

#ifdef LTC_RC4
DLLEXPORT int rc4_start(prng_state *prng);
DLLEXPORT int rc4_add_entropy(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int rc4_ready(prng_state *prng);
DLLEXPORT unsigned long rc4_read(unsigned char *out, unsigned long outlen, prng_state *prng);
DLLEXPORT int  rc4_done(prng_state *prng);
DLLEXPORT int  rc4_export(unsigned char *out, unsigned long *outlen, prng_state *prng);
DLLEXPORT int  rc4_import(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int  rc4_test(void);
extern const struct ltc_prng_descriptor rc4_desc;
#endif

#ifdef LTC_SPRNG
DLLEXPORT int sprng_start(prng_state *prng);
DLLEXPORT int sprng_add_entropy(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int sprng_ready(prng_state *prng);
DLLEXPORT unsigned long sprng_read(unsigned char *out, unsigned long outlen, prng_state *prng);
DLLEXPORT int sprng_done(prng_state *prng);
DLLEXPORT int  sprng_export(unsigned char *out, unsigned long *outlen, prng_state *prng);
DLLEXPORT int  sprng_import(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int  sprng_test(void);
extern const struct ltc_prng_descriptor sprng_desc;
#endif

#ifdef LTC_SOBER128
DLLEXPORT int sober128_start(prng_state *prng);
DLLEXPORT int sober128_add_entropy(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int sober128_ready(prng_state *prng);
DLLEXPORT unsigned long sober128_read(unsigned char *out, unsigned long outlen, prng_state *prng);
DLLEXPORT int sober128_done(prng_state *prng);
DLLEXPORT int  sober128_export(unsigned char *out, unsigned long *outlen, prng_state *prng);
DLLEXPORT int  sober128_import(const unsigned char *in, unsigned long inlen, prng_state *prng);
DLLEXPORT int  sober128_test(void);
extern const struct ltc_prng_descriptor sober128_desc;
#endif

DLLEXPORT int find_prng(const char *name);
DLLEXPORT int register_prng(const struct ltc_prng_descriptor *prng);
DLLEXPORT int unregister_prng(const struct ltc_prng_descriptor *prng);
DLLEXPORT int prng_is_valid(int idx);
LTC_MUTEX_PROTO(ltc_prng_mutex)

/* Slow RNG you **might** be able to use to seed a PRNG with.  Be careful as this
 * might not work on all platforms as planned
 */
DLLEXPORT unsigned long rng_get_bytes(unsigned char *out, 
                            unsigned long outlen, 
                            void (*callback)(void));

DLLEXPORT int rng_make_prng(int bits, int wprng, prng_state *prng, void (*callback)(void));


/* $Source: /cvs/libtom/libtomcrypt/src/headers/tomcrypt_prng.h,v $ */
/* $Revision: 1.9 $ */
/* $Date: 2007/05/12 14:32:35 $ */
