///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2021 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 2/3/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_SEA_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_SEA_MAIN_HPP

#include "xos/app/console/crypto/sea/main_opt.hpp"
/*#include "xos/crypto/cipher/aes/devine/implemented.hpp"
*/

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace sea {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    /*typedef xos::crypto::cipher::implement cipher_t;
    typedef xos::crypto::cipher::aes::implement aes_cipher_t;
    typedef xos::crypto::cipher::aes::devine::implemented devine_aes_cipher_t;
    typedef devine_aes_cipher_t default_aes_cipher_t;*/

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(/*): aes_key_(0), aes_iv_(0*/) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /*/// encipher_run
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->aes_encipher_run(argc, argv, env);
        return err;
    }
    /// decipher_run
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->aes_decipher_run(argc, argv, env);
        return err;
    }
    /// test_run
    virtual int test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->aes_test_run(argc, argv, env);
        return err;
    }
    /// ...get_plain_run
    virtual int get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->aes_plain_text(plain_chars, sizeof_plain_text))) {
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
        }
        return err;
    }
    /// ...get_cipher_run
    virtual int get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->aes_cipher_text(sizeof_cipher_text))) {
            this->output_x(cipher_text, sizeof_cipher_text);
        }
        return err;
    }
    /// ...cipher_key / ...cipher_iv
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        return aes_key(sizeof_cipher_key);
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        return aes_iv(sizeof_cipher_iv);
    }

    /// aes_encipher_run
    virtual int aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            const byte_t* aes_key = 0;
            size_t sizeof_aes_key = 0;

            if ((aes_key = this->aes_key(sizeof_aes_key))) {
                const byte_t* aes_iv = 0;
                size_t sizeof_aes_iv = 0;

                if ((aes_iv = this->aes_iv(sizeof_aes_iv))) {
                    byte_t* encipher_text = 0;
                    size_t sizeof_encipher_text = 0;
    
                    if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                        default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                        
                        if (0 < (length = aes.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            this->output_x(encipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    /// aes_decipher_run
    virtual int aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
            const byte_t* aes_key = 0;
            size_t sizeof_aes_key = 0;

            if ((aes_key = this->aes_key(sizeof_aes_key))) {
                const byte_t* aes_iv = 0;
                size_t sizeof_aes_iv = 0;

                if ((aes_iv = this->aes_iv(sizeof_aes_iv))) {
                    byte_t* decipher_text = 0;
                    size_t sizeof_decipher_text = 0;
    
                    if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                        default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                        size_t encipher_text_size = this->encipher_text_size();
                        
                        if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                            sizeof_encipher_text = encipher_text_size;
                        }
                        if (0 < (length = aes.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                            this->output_x(decipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...aes_key...
    const byte_t* (derives::*aes_key_)(size_t& sizeof_aes_key) const;
    virtual const byte_t* aes_key(size_t& sizeof_aes_key) const {
        if (aes_key_) {
            return (this->*aes_key_)(sizeof_aes_key);
        }
        return test_aes_key(sizeof_aes_key);
    }
    virtual const byte_t* extends_cipher_key(size_t& sizeof_cipher_key) const {
        return extends::cipher_key(sizeof_cipher_key);
    }
    virtual int on_cipher_key_set
    (byte_t* cipher_key, size_t sizeof_cipher_key, size_t cipher_key_size) {
        int err = 0;
        aes_key_ = &derives::extends_cipher_key;
        return err;
    }

    /// ...aes_iv...
    const byte_t* (derives::*aes_iv_)(size_t& sizeof_aes_iv) const;
    virtual const byte_t* aes_iv(size_t& sizeof_aes_iv) const {
        if (aes_iv_) {
            return (this->*aes_iv_)(sizeof_aes_iv);
        }
        return test_aes_iv(sizeof_aes_iv);
    }
    virtual const byte_t* extends_cipher_iv(size_t& sizeof_cipher_iv) const {
        return extends::cipher_iv(sizeof_cipher_iv);
    }
    virtual int on_cipher_iv_set
    (byte_t* cipher_iv, size_t sizeof_cipher_iv, size_t cipher_iv_size) {
        int err = 0;
        aes_iv_ = &derives::extends_cipher_iv;
        return err;
    }

    /// ...aes_plain_text...
    const byte_t* (derives::*aes_plain_text_)(const char_t*& chars, size_t& sizeof_aes_plain_text) const;
    virtual const byte_t* aes_plain_text(const char_t*& chars, size_t& sizeof_aes_plain_text) const {
        if (aes_plain_text_) {
            return (this->*aes_plain_text_)(chars, sizeof_aes_plain_text);
        }
        chars = 0;
        return test_aes_plain_text(sizeof_aes_plain_text);
    }
    virtual const byte_t* extends_plain_text(const char_t*& chars, size_t& sizeof_plain_text) const {
        chars = extends::plain_text(sizeof_plain_text);
        return ((const byte_t*)chars);
    }
    virtual int on_plain_text_set(const char_t* to) {
        int err = 0;
        aes_plain_text_ = &derives::extends_plain_text;
        return err;
    }

    /// ...aes_cipher_text...
    const byte_t* (derives::*aes_cipher_text_)(size_t& sizeof_aes_cipher_text) const;
    virtual const byte_t* aes_cipher_text(size_t& sizeof_aes_cipher_text) const {
        if (aes_cipher_text_) {
            return (this->*aes_cipher_text_)(sizeof_aes_cipher_text);
        }
        return test_aes_cipher_text(sizeof_aes_cipher_text);
    }
    virtual const byte_t* extends_cipher_text(size_t& sizeof_cipher_text) const {
        return extends::cipher_test(sizeof_cipher_text);
    }
    virtual int on_cipher_test_set
    (const byte_t* cipher_test, size_t sizeof_cipher_test, size_t cipher_test_size) {
        int err = 0;
        aes_cipher_text_ = &derives::extends_cipher_text;
        return err;
    }

    /// aes_test_run
    virtual int aes_test_run(int argc, char_t** argv, char_t** env) {
        size_t sizeof_aes_key = 0;
        const byte_t* aes_key = this->aes_key(sizeof_aes_key);

        size_t sizeof_aes_iv = 0;
        const byte_t* aes_iv = this->aes_iv(sizeof_aes_iv);

        size_t sizeof_plain_text = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = this->aes_plain_text(plain_chars, sizeof_plain_text);

        size_t sizeof_cipher_text = 0;
        const byte_t* cipher_text = this->aes_cipher_text(sizeof_cipher_text);

        size_t sizeof_encipher_text = 0;
        byte_t* encipher_text = this->encipher_text(sizeof_encipher_text); 

        size_t sizeof_decipher_text = 0;
        byte_t* decipher_text = this->decipher_text(sizeof_decipher_text);

        ssize_t length = 0;
        int err = 0;

        if ((plain_text) && (sizeof_plain_text)) {
            this->out("   plain-text: "); 
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
    
            if ((aes_key) && (sizeof_aes_key)) {

                if ((aes_iv) && (sizeof_aes_iv)) {

                    if ((encipher_text) && (sizeof_encipher_text)) {
                        default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                        
                        if (0 < (length = aes.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            this->out("  cipher-text: "); 
                            this->output_x(encipher_text, length);
            
                            if ((bytes_t::compare(encipher_text, cipher_text, sizeof_cipher_text))) {
                                this->errln("encipher_text != cipher_text");
                                err = 1;
                            }
                        } else {
                            this->errln("failed on encrypt()");
                            return 1;
                        }
                    }
                    if ((decipher_text) && (sizeof_decipher_text)) {

                        if ((length) && (length <= sizeof_decipher_text)) {
                            default_aes_cipher_t aes(aes_key, sizeof_aes_key, aes_iv, sizeof_aes_iv);
                
                            if (sizeof_plain_text <= (length = aes.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
                                this->out("decipher-text: "); 
                                this->output_x(decipher_text, length);
                
                                if ((bytes_t::compare(decipher_text, plain_text, sizeof_plain_text))) {
                                    this->errln("decipher_text != plain_text");
                                    err = 1;
                                }
                            } else {
                                this->errln("failed on decrypt()");
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual const byte_t* test_aes_key(size_t& sizeof_aes_key) const {
        static const byte_t aes_key[8*3] = {
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
            0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        sizeof_aes_key = sizeof(aes_key);
        return aes_key;
    }
    virtual const byte_t* test_aes_iv(size_t& sizeof_aes_iv) const {
        static const byte_t aes_iv[8*2] = {
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10,
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef
        };
        sizeof_aes_iv = sizeof(aes_iv);
        return aes_iv;
    }
    virtual const byte_t* test_aes_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x31,0x00,0x00
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    virtual const byte_t* test_aes_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*4] = {
            0x38,0x2A,0xB1,0xB3,0xD5,0x33,0x6B,0x09,
            0x64,0xDE,0x64,0x01,0x32,0x4C,0x05,0x38,
            0x4B,0xBB,0x0A,0x3A,0x7B,0xF5,0xE5,0x0C,
            0x20,0xA7,0x80,0xD1,0x5E,0xC3,0x37,0xEF
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }*/
}; /// class maint
typedef maint<> main;

} /// namespace sea
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_SEA_MAIN_HPP
