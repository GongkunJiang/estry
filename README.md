repo init -u ssh://jianggongkun@gerrit.eswincomputing.com:29418/e315s/manifest -b e315s-d_saas --repo-url=ssh://jianggongkun@gerrit.eswincomputing.com:29418/tools/git-repo
repo sync -cdj4 --no-tags

From ssh://gerrit.eswincomputing.com:29418/eswin/fota_saas
 * [new branch]      e315s-d_saas -> origin/e315s-d_saas


gcc main.c -o eswin_fota_sign -L. -lmbedcrypto -I../../mbedtls-2.27.0/include -I..
gcc main.c ../signing.c -o eswin_fota_sign -L. -lmbedcrypto -I../../mbedtls-2.27.0/include

./eswin_fota_sign -d sha256 ../priv_key/rsa_private_key.pem ./in/image ./out/hash.sig
./eswin_fota_sign -d sha256 ../priv_key/ec_private_key.pem ./in/image ./out/hash.sig

openssl ecparam -name secp256r1 -genkey -noout -out ../priv_key/ec_private_key.pem
openssl pkey -in ../priv_key/ec_private_key.pem -pubout -out ./pub_key/ec_public_key.pem


[signing] Add mbedtls library and signing interface.

Issue: BECM-409

git commit --amend
git push origin HEAD:refs/for/e315s-d_saas

ln -sT ../../../external/mbedtls-2.27.0 mbedtls-2.27.0

coding_format.sh

git rebase origin/e315s-d_saas


# error while loading shared libraries: libgmssl.so.3
sudo ldconfig
