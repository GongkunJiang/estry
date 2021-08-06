#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/md.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/platform.h"

// __LINE__：在源代码中插入当前源代码行号
#define assert_exit(cond, ret) \
    do { if (!(cond)) { \
        printf("  !. assert: failed [line: %d, error: -0x%04X]\n", __LINE__, -ret); \
        goto cleanup; \
    } } while (0)

static void dump_buf(char *info, uint8_t *buf, uint32_t len)
{
    mbedtls_printf("%s", info); // config.h 2870
    for (int i = 0; i < len; i++) {
        mbedtls_printf("%s%02X%s", i % 16 == 0 ? "\n     ":" ", 
                        buf[i], i == len - 1 ? "\n":"");
    }
}

int main(void)
{
    int ret = 0;
    char buf[97];
    uint8_t hash[32], msg[100];// typedef unsigned char           uint8_t;
    uint8_t *pers = "simple_ecdsa";// typedef unsigned char           uint8_t;用于填充prngseed
    /*
        size_t主要用于计数，如sizeof函数返回值类型即为size_t。
        在不同位的机器中所占的位数也不同，size_t是无符号数，ssize_t是有符号数。
        在32位机器中定义为：typedef  unsigned int size_t; （4个字节）
        在64位机器中定义为：typedef  unsigned long size_t;（8个字节）
    */
    size_t rlen, slen, qlen, dlen;
    memset(msg, 0xab, sizeof(msg));//用0x12填充msg
    //mbedtls_platform_set_printf(printf);

    mbedtls_mpi r, s;// MPI (Multi-precision integer) structure bignum.h 203
    mbedtls_ecdsa_context ctx;//typedef mbedtls_ecp_keypair mbedtls_ecdsa_context; ecp.h 204
    mbedtls_md_context_t md_ctx;//The generic message-digest context. md.h 117
    mbedtls_entropy_context entropy;//Entropy context structure  entropy.h 146
    // PRNG from a block-cipher in counter mode operation Using Deterministic Random Bit Generators
    mbedtls_ctr_drbg_context ctr_drbg;//The CTR_DRBG context structure. ctr_drbg.h 168

    mbedtls_mpi_init(&r);
    mbedtls_mpi_init(&s);
    mbedtls_ecdsa_init(&ctx);  //初始化ECDSA结构体
    mbedtls_entropy_init(&entropy);
    mbedtls_ctr_drbg_init(&ctr_drbg);

    // This function seeds and sets up the CTR_DRBG entropy source for future reseeds.
    ret = mbedtls_ctr_drbg_seed(&ctr_drbg, mbedtls_entropy_func, &entropy, 
                                (const uint8_t *) pers, strlen(pers));
    assert_exit(ret == 0, ret);
    mbedtls_printf("\n  . setup rng ... ok\n\n");
    mbedtls_md_init(&md_ctx);

    mbedtls_md(mbedtls_md_info_from_type(MBEDTLS_MD_SHA256), msg, sizeof(msg), hash);
    mbedtls_printf("  1. hash msg ... ok\n");//计算出msg的hash值

    //产生ECDSA密钥对
    ret = mbedtls_ecdsa_genkey(&ctx, MBEDTLS_ECP_DP_SECP256R1,//选择SECP256R1
                              mbedtls_ctr_drbg_random, &ctr_drbg);
    assert_exit(ret == 0, ret);
    mbedtls_ecp_point_write_binary(&ctx.grp, &ctx.Q, 
                            MBEDTLS_ECP_PF_UNCOMPRESSED, &qlen, buf, sizeof(buf));
    dlen = mbedtls_mpi_size(&ctx.d);
    mbedtls_mpi_write_binary(&ctx.d, buf + qlen, dlen);
    dump_buf("  2. ecdsa generate keypair:", buf, qlen + dlen);

    //ECDSA签名，得到r , s
    ret = mbedtls_ecdsa_sign(&ctx.grp, &r, &s, &ctx.d, 
                        hash, sizeof(hash), mbedtls_ctr_drbg_random, &ctr_drbg);
    assert_exit(ret == 0, ret);
    rlen = mbedtls_mpi_size(&r);
    slen = mbedtls_mpi_size(&s);
    mbedtls_mpi_write_binary(&r, buf, rlen);
    mbedtls_mpi_write_binary(&s, buf + rlen, slen);
    dump_buf("  3. ecdsa generate signature:", buf, rlen + slen);

	//ECDSA验签，返回0表示验证成功
    ret = mbedtls_ecdsa_verify(&ctx.grp, hash, sizeof(hash), &ctx.Q, &r, &s);
    assert_exit(ret == 0, ret);
    mbedtls_printf("  4. ecdsa verify signature ... ok\n\n");

cleanup:
    mbedtls_mpi_free(&r);
    mbedtls_mpi_free(&s);
    mbedtls_md_free(&md_ctx);
    mbedtls_ecdsa_free(&ctx);
    mbedtls_ctr_drbg_free(&ctr_drbg);
    mbedtls_entropy_free(&entropy);

    return(ret != 0);
}

