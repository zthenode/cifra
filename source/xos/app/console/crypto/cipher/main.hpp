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
///   Date: 1/27/2021, 9/29/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP

#include "xos/app/console/crypto/cipher/main_opt.hpp"
#include "xos/crypto/cipher/aes/devine/implemented.hpp"
#include "xos/crypto/cipher/des3/openssl/implemented.hpp"
#include "xos/crypto/cipher/rc4/etiris/implemented.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives; 
    
    enum cipher_algorithm_t {
        cipher_algorithm_none,
        cipher_algorithm_aes,
        cipher_algorithm_des3,
        cipher_algorithm_rc4,
        next_cipher_algorithm,
        first_cipher_algorithm = (cipher_algorithm_none + 1),
        last_cipher_algorithm = (next_cipher_algorithm - 1)
    };

    typedef xos::crypto::cipher::implement cipher_t;
    typedef xos::crypto::cipher::aes::implement aes_cipher_t;
    typedef xos::crypto::cipher::aes::devine::implemented devine_aes_cipher_t;
    typedef devine_aes_cipher_t default_aes_cipher_t;
    typedef xos::crypto::cipher::des3::implement des3_cipher_t;
    typedef xos::crypto::cipher::des3::openssl::implemented openssl_des3_cipher_t;
    typedef openssl_des3_cipher_t default_des3_cipher_t;
    typedef xos::crypto::cipher::rc4::implement rc4_cipher_t;
    typedef xos::crypto::cipher::rc4::etiris::implemented etiris_rc4_cipher_t;
    typedef etiris_rc4_cipher_t default_rc4_cipher_t;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructors / destructor
    maint(): cipher_algorithm_(cipher_algorithm_none) {
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

    /// ...encipher_run
    int (derives::*encipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (encipher_run_) {
            err = (this->*encipher_run_)(argc, argv, env);
        } else {
            err = default_encipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = aes_encipher_run(argc, argv, env);
        return err;
    }
    virtual int set_aes_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::aes_encipher_run;
        return err;
    }
    virtual int set_des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::des3_encipher_run;
        return err;
    }
    virtual int set_rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        encipher_run_ = &derives::rc4_encipher_run;
        return err;
    }

    /// ...decipher_run
    int (derives::*decipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (decipher_run_) {
            err = (this->*decipher_run_)(argc, argv, env);
        } else {
            err = default_decipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = aes_decipher_run(argc, argv, env);
        return err;
    }
    virtual int set_aes_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::aes_decipher_run;
        return err;
    }
    virtual int set_des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::des3_decipher_run;
        return err;
    }
    virtual int set_rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        decipher_run_ = &derives::rc4_decipher_run;
        return err;
    }

    /// ...test_run
    int (derives::*test_run_)(int argc, char_t** argv, char_t** env);
    virtual int test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (test_run_) {
            err = (this->*test_run_)(argc, argv, env);
        } else {
            err = default_test_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = aes_test_run(argc, argv, env);
        return err;
    }
    virtual int set_aes_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_run_ = &derives::aes_test_run;
        return err;
    }
    virtual int set_des3_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_run_ = &derives::des3_test_run;
        return err;
    }
    virtual int set_rc4_test_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        test_run_ = &derives::rc4_test_run;
        return err;
    }

    /// ...get_plain_run
    int (derives::*get_plain_run_)(int argc, char_t** argv, char_t** env);
    virtual int get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (get_plain_run_) {
            err = (this->*get_plain_run_)(argc, argv, env);
        } else {
            err = default_get_plain_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = aes_get_plain_run(argc, argv, env);
        return err;
    }
    virtual int set_aes_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_plain_run_ = &derives::aes_get_plain_run;
        return err;
    }
    virtual int set_des3_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_plain_run_ = &derives::des3_get_plain_run;
        return err;
    }
    virtual int set_rc4_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_plain_run_ = &derives::rc4_get_plain_run;
        return err;
    }

    /// ...get_cipher_run
    int (derives::*get_cipher_run_)(int argc, char_t** argv, char_t** env);
    virtual int get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (get_cipher_run_) {
            err = (this->*get_cipher_run_)(argc, argv, env);
        } else {
            err = default_get_cipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = aes_get_cipher_run(argc, argv, env);
        return err;
    }
    virtual int set_aes_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_cipher_run_ = &derives::aes_get_cipher_run;
        return err;
    }
    virtual int set_des3_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_cipher_run_ = &derives::des3_get_cipher_run;
        return err;
    }
    virtual int set_rc4_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_cipher_run_ = &derives::rc4_get_cipher_run;
        return err;
    }

    /// ...cipher_key
    const byte_t* (derives::*cipher_key_)(size_t& sizeof_cipher_key) const;
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        const byte_t* key = 0;
        if (cipher_key_) {
            key = (this->*cipher_key_)(sizeof_cipher_key);
        } else {
            key = default_cipher_key(sizeof_cipher_key);
        }
        return key;
    }
    virtual const byte_t* default_cipher_key(size_t& sizeof_cipher_key) const {
        const byte_t* key = 0;
        key = aes_cipher_key(sizeof_cipher_key);
        return key;
    }
    virtual int set_aes_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_key_ = &derives::aes_cipher_key;
        return err;
    }
    virtual int set_des3_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_key_ = &derives::des3_cipher_key;
        return err;
    }
    virtual int set_rc4_cipher_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_key_ = &derives::rc4_cipher_key;
        return err;
    }

    /// ...cipher_iv
    const byte_t* (derives::*cipher_iv_)(size_t& sizeof_cipher_iv) const;
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        const byte_t* iv = 0;
        if (cipher_iv_) {
            iv = (this->*cipher_iv_)(sizeof_cipher_iv);
        } else {
            iv = default_cipher_iv(sizeof_cipher_iv);
        }
        return iv;
    }
    virtual const byte_t* default_cipher_iv(size_t& sizeof_cipher_iv) const {
        const byte_t* iv = 0;
        iv = aes_cipher_iv(sizeof_cipher_iv);
        return iv;
    }
    virtual int set_aes_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_iv_ = &derives::aes_cipher_iv;
        return err;
    }
    virtual int set_des3_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_iv_ = &derives::des3_cipher_iv;
        return err;
    }
    virtual int set_rc4_cipher_iv_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        cipher_iv_ = &derives::rc4_cipher_iv;
        return err;
    }

    /// ...set_..._cipher_run
    virtual int set_aes_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_aes_encipher_run(argc, argv, env))) {
            if (!(err = set_aes_decipher_run(argc, argv, env))) {
                if (!(err = set_aes_test_run(argc, argv, env))) {
                    if (!(err = set_aes_get_plain_run(argc, argv, env))) {
                        if (!(err = set_aes_get_plain_run(argc, argv, env))) {
                            if (!(err = set_aes_cipher_key_run(argc, argv, env))) {
                                if (!(err = set_aes_cipher_iv_run(argc, argv, env))) {
                                    cipher_algorithm_ = cipher_algorithm_aes;
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int set_des3_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_des3_encipher_run(argc, argv, env))) {
            if (!(err = set_des3_decipher_run(argc, argv, env))) {
                if (!(err = set_des3_test_run(argc, argv, env))) {
                    if (!(err = set_des3_get_plain_run(argc, argv, env))) {
                        if (!(err = set_des3_get_cipher_run(argc, argv, env))) {
                            if (!(err = set_des3_cipher_key_run(argc, argv, env))) {
                                if (!(err = set_des3_cipher_iv_run(argc, argv, env))) {
                                    cipher_algorithm_ = cipher_algorithm_des3;
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int set_rc4_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_rc4_encipher_run(argc, argv, env))) {
            if (!(err = set_rc4_decipher_run(argc, argv, env))) {
                if (!(err = set_rc4_test_run(argc, argv, env))) {
                    if (!(err = set_rc4_get_plain_run(argc, argv, env))) {
                        if (!(err = set_rc4_get_plain_run(argc, argv, env))) {
                            if (!(err = set_rc4_cipher_key_run(argc, argv, env))) {
                                if (!(err = set_rc4_cipher_iv_run(argc, argv, env))) {
                                    cipher_algorithm_ = cipher_algorithm_rc4;
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }

    ///
    /// aes
    /// ...

    /// ...aes_cipher_key
    virtual const byte_t* aes_cipher_key(size_t& sizeof_cipher_key) const {
        return aes_key(sizeof_cipher_key);
    }
    /// ...aes_cipher_iv
    virtual const byte_t* aes_cipher_iv(size_t& sizeof_cipher_iv) const {
        return aes_iv(sizeof_cipher_iv);
    }
    /// ...aes_get_plain_run
    virtual int aes_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->aes_plain_text(plain_chars, sizeof_plain_text))) {
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
        }
        return err;
    }
    /// ...aes_get_cipher_run
    virtual int aes_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->aes_cipher_text(sizeof_cipher_text))) {
            this->output_x(cipher_text, sizeof_cipher_text);
        }
        return err;
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
    }
    /// ...aes_key...
    const byte_t* (derives::*aes_key_)(size_t& sizeof_aes_key) const;
    virtual const byte_t* aes_key(size_t& sizeof_aes_key) const {
        if (aes_key_) {
            return (this->*aes_key_)(sizeof_aes_key);
        }
        return test_aes_key(sizeof_aes_key);
    }
    /// ...aes_iv...
    const byte_t* (derives::*aes_iv_)(size_t& sizeof_aes_iv) const;
    virtual const byte_t* aes_iv(size_t& sizeof_aes_iv) const {
        if (aes_iv_) {
            return (this->*aes_iv_)(sizeof_aes_iv);
        }
        return test_aes_iv(sizeof_aes_iv);
    }
    /// ...aes_plain_text...
    const byte_t* (derives::*aes_plain_text_)(const char_t*& chars, size_t& sizeof_aes_plain_text) const;
    virtual const byte_t* aes_plain_text(const char_t*& chars, size_t& sizeof_aes_plain_text) const {
        if (aes_plain_text_) {
            return (this->*aes_plain_text_)(chars, sizeof_aes_plain_text);
        }
        return test_aes_plain_text(sizeof_aes_plain_text);
    }
    /// ...aes_cipher_text...
    const byte_t* (derives::*aes_cipher_text_)(size_t& sizeof_aes_cipher_text) const;
    virtual const byte_t* aes_cipher_text(size_t& sizeof_aes_cipher_text) const {
        if (aes_cipher_text_) {
            return (this->*aes_cipher_text_)(sizeof_aes_cipher_text);
        }
        return test_aes_cipher_text(sizeof_aes_cipher_text);
    }

    /// ...
    /// aes
    /// 

    ///
    /// des3
    /// ...

    /// ...des3_cipher_key
    virtual const byte_t* des3_cipher_key(size_t& sizeof_cipher_key) const {
        return des3_key(sizeof_cipher_key);
    }
    /// ...des3_cipher_iv
    virtual const byte_t* des3_cipher_iv(size_t& sizeof_cipher_iv) const {
        return des3_iv(sizeof_cipher_iv);
    }
    /// ...des3_get_plain_run
    virtual int des3_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->des3_plain_text(plain_chars, sizeof_plain_text))) {
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
        }
        return err;
    }
    /// ...des3_get_cipher_run
    virtual int des3_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->des3_cipher_text(sizeof_cipher_text))) {
            this->output_x(cipher_text, sizeof_cipher_text);
        }
        return err;
    }
    /// des3_encipher_run
    virtual int des3_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            const byte_t* des3_key = 0;
            size_t sizeof_des3_key = 0;

            if ((des3_key = this->des3_key(sizeof_des3_key))) {
                const byte_t* des3_iv = 0;
                size_t sizeof_des3_iv = 0;

                if ((des3_iv = this->des3_iv(sizeof_des3_iv))) {
                    byte_t* encipher_text = 0;
                    size_t sizeof_encipher_text = 0;
    
                    if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                        default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                        
                        if (0 < (length = des3.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                            this->output_x(encipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    /// des3_decipher_run
    virtual int des3_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
            const byte_t* des3_key = 0;
            size_t sizeof_des3_key = 0;

            if ((des3_key = this->des3_key(sizeof_des3_key))) {
                const byte_t* des3_iv = 0;
                size_t sizeof_des3_iv = 0;

                if ((des3_iv = this->des3_iv(sizeof_des3_iv))) {
                    byte_t* decipher_text = 0;
                    size_t sizeof_decipher_text = 0;
    
                    if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                        default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                        size_t encipher_text_size = this->encipher_text_size();
                        
                        if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                            sizeof_encipher_text = encipher_text_size;
                        }
                        if (0 < (length = des3.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                            this->output_x(decipher_text, length);
                        }
                    }
                }
            }
        }
        return err;
    }
    /// des3_test_run
    virtual int des3_test_run(int argc, char_t** argv, char_t** env) {
        size_t sizeof_des3_key = 0;
        const byte_t* des3_key = this->des3_key(sizeof_des3_key);

        size_t sizeof_des3_iv = 0;
        const byte_t* des3_iv = this->des3_iv(sizeof_des3_iv);

        size_t sizeof_plain_text = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = this->des3_plain_text(plain_chars, sizeof_plain_text);

        size_t sizeof_cipher_text = 0;
        const byte_t* cipher_text = this->des3_cipher_text(sizeof_cipher_text);

        size_t sizeof_encipher_text = 0;
        byte_t* encipher_text = this->encipher_text(sizeof_encipher_text); 

        size_t sizeof_decipher_text = 0;
        byte_t* decipher_text = this->decipher_text(sizeof_decipher_text);

        ssize_t length = 0;
        int err = 0;

        if ((plain_text) && (sizeof_plain_text)) {
            this->out("   plain-text: "); 
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
    
            if ((des3_key) && (sizeof_des3_key)) {

                if ((des3_iv) && (sizeof_des3_iv)) {

                    if ((encipher_text) && (sizeof_encipher_text)) {
                        default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                        
                        if (0 < (length = des3.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
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
                            default_des3_cipher_t des3(des3_key, sizeof_des3_key, des3_iv, sizeof_des3_iv);
                
                            if (sizeof_plain_text <= (length = des3.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
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
    virtual const byte_t* test_des3_key(size_t& sizeof_des3_key) const {
        static const byte_t des3_key[8*3] = {
            0x01,0x23,0x45,0x67,0x89,0xab,0xcd,0xef,
            0xf1,0xe0,0xd3,0xc2,0xb5,0xa4,0x97,0x86,
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        sizeof_des3_key = sizeof(des3_key);
        return des3_key;
    }
    virtual const byte_t* test_des3_iv(size_t& sizeof_des3_iv) const {
        static const byte_t des3_iv[8*1] = {
            0xfe,0xdc,0xba,0x98,0x76,0x54,0x32,0x10
        };
        sizeof_des3_iv = sizeof(des3_iv);
        return des3_iv;
    }
    virtual const byte_t* test_des3_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*4] = {
            0x37,0x36,0x35,0x34,0x33,0x32,0x31,0x20,
            0x4E,0x6F,0x77,0x20,0x69,0x73,0x20,0x74,
            0x68,0x65,0x20,0x74,0x69,0x6D,0x65,0x20,
            0x66,0x6F,0x72,0x20,0x00,0x00,0x00,0x00
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    virtual const byte_t* test_des3_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*4] = {
            0x3F,0xE3,0x01,0xC9,0x62,0xAC,0x01,0xD0,
            0x22,0x13,0x76,0x3C,0x1C,0xBD,0x4C,0xDC,
            0x79,0x96,0x57,0xC0,0x64,0xEC,0xF5,0xD4,
            0x1C,0x67,0x38,0x12,0xCF,0xDE,0x96,0x75
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...des3_key...
    const byte_t* (derives::*des3_key_)(size_t& sizeof_des3_key) const;
    virtual const byte_t* des3_key(size_t& sizeof_des3_key) const {
        if (des3_key_) {
            return (this->*des3_key_)(sizeof_des3_key);
        }
        return test_des3_key(sizeof_des3_key);
    }
    /// ...des3_iv...
    const byte_t* (derives::*des3_iv_)(size_t& sizeof_des3_iv) const;
    virtual const byte_t* des3_iv(size_t& sizeof_des3_iv) const {
        if (des3_iv_) {
            return (this->*des3_iv_)(sizeof_des3_iv);
        }
        return test_des3_iv(sizeof_des3_iv);
    }
    /// ...des3_plain_text...
    const byte_t* (derives::*des3_plain_text_)(const char_t*& chars, size_t& sizeof_des3_plain_text) const;
    virtual const byte_t* des3_plain_text(const char_t*& chars, size_t& sizeof_des3_plain_text) const {
        if (des3_plain_text_) {
            return (this->*des3_plain_text_)(chars, sizeof_des3_plain_text);
        }
        return test_des3_plain_text(sizeof_des3_plain_text);
    }
    /// ...des3_cipher_text...
    const byte_t* (derives::*des3_cipher_text_)(size_t& sizeof_des3_cipher_text) const;
    virtual const byte_t* des3_cipher_text(size_t& sizeof_des3_cipher_text) const {
        if (des3_cipher_text_) {
            return (this->*des3_cipher_text_)(sizeof_des3_cipher_text);
        }
        return test_des3_cipher_text(sizeof_des3_cipher_text);
    }

    /// ...
    /// des3
    /// 

    ///
    /// rc4
    /// ...

    /// ...rc4_cipher_key
    virtual const byte_t* rc4_cipher_key(size_t& sizeof_cipher_key) const {
        return rc4_key(sizeof_cipher_key);
    }
    /// ...rc4_cipher_iv
    virtual const byte_t* rc4_cipher_iv(size_t& sizeof_cipher_iv) const {
        return rc4_iv(sizeof_cipher_iv);
    }
    /// ...rc4_get_plain_run
    virtual int rc4_get_plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = 0;
        size_t sizeof_plain_text = 0;

        if ((plain_text = this->rc4_plain_text(plain_chars, sizeof_plain_text))) {
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
        }
        return err;
    }
    /// ...rc4_get_cipher_run
    virtual int rc4_get_cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* cipher_text = 0;
        size_t sizeof_cipher_text = 0;

        if ((cipher_text = this->rc4_cipher_text(sizeof_cipher_text))) {
            this->output_x(cipher_text, sizeof_cipher_text);
        }
        return err;
    }
    /// rc4_encipher_run
    virtual int rc4_encipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* plain_text = 0;
        size_t sizeof_plain_text = 0;
        ssize_t length = 0;

        if ((plain_text = this->plain_text(sizeof_plain_text))) {
            const byte_t* rc4_key = 0;
            size_t sizeof_rc4_key = 0;

            if ((rc4_key = this->rc4_key(sizeof_rc4_key))) {
                const byte_t* rc4_iv = 0;
                size_t sizeof_rc4_iv = 0;
                byte_t* encipher_text = 0;
                size_t sizeof_encipher_text = 0;

                if ((rc4_iv = this->rc4_iv(sizeof_rc4_iv))) {
                }
                if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                    default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
                    
                    if (0 < (length = rc4.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
                        this->output_x(encipher_text, length);
                    }
                }
            }
        }
        return err;
    }
    /// rc4_decipher_run
    virtual int rc4_decipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        byte_t* encipher_text = 0;
        size_t sizeof_encipher_text = 0;
        ssize_t length = 0;

        if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
            const byte_t* rc4_key = 0;
            size_t sizeof_rc4_key = 0;

            if ((rc4_key = this->rc4_key(sizeof_rc4_key))) {
                const byte_t* rc4_iv = 0;
                size_t sizeof_rc4_iv = 0;
                byte_t* decipher_text = 0;
                size_t sizeof_decipher_text = 0;

                if ((rc4_iv = this->rc4_iv(sizeof_rc4_iv))) {
                }
                if ((decipher_text = this->decipher_text(sizeof_decipher_text))) {
                    default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
                    size_t encipher_text_size = this->encipher_text_size();
                    
                    if ((encipher_text_size) && (encipher_text_size < sizeof_encipher_text)) {
                        sizeof_encipher_text = encipher_text_size;
                    }
                    if (0 < (length = rc4.decrypt(decipher_text, sizeof_decipher_text, encipher_text, sizeof_encipher_text))) {
                        this->output_x(decipher_text, length);
                    }
                }
            }
        }
        return err;
    }
    /// rc4_test_run
    virtual int rc4_test_run(int argc, char_t** argv, char_t** env) {
        size_t sizeof_rc4_key = 0;
        const byte_t* rc4_key = this->rc4_key(sizeof_rc4_key);

        size_t sizeof_rc4_iv = 0;
        const byte_t* rc4_iv = this->rc4_iv(sizeof_rc4_iv);

        size_t sizeof_plain_text = 0;
        const char_t* plain_chars = 0;
        const byte_t* plain_text = this->rc4_plain_text(plain_chars, sizeof_plain_text);

        size_t sizeof_cipher_text = 0;
        const byte_t* cipher_text = this->rc4_cipher_text(sizeof_cipher_text);

        size_t sizeof_encipher_text = 0;
        byte_t* encipher_text = this->encipher_text(sizeof_encipher_text); 

        size_t sizeof_decipher_text = 0;
        byte_t* decipher_text = this->decipher_text(sizeof_decipher_text);

        ssize_t length = 0;
        int err = 0;

        if ((plain_text) && (sizeof_plain_text)) {
            this->out("   plain-text: "); 
            this->output_x(plain_chars, plain_text, sizeof_plain_text);
    
            if ((rc4_key) && (sizeof_rc4_key)) {

                if ((rc4_iv) && (sizeof_rc4_iv)) {
                }
                if ((encipher_text) && (sizeof_encipher_text)) {
                    default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
                    
                    if (0 < (length = rc4.encrypt(encipher_text, sizeof_encipher_text, plain_text, sizeof_plain_text))) {
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
                        default_rc4_cipher_t rc4(rc4_key, sizeof_rc4_key);
            
                        if (sizeof_plain_text <= (length = rc4.decrypt(decipher_text, sizeof_decipher_text, encipher_text, length))) {
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
        return err;
    }
    virtual const byte_t* test_rc4_key(size_t& sizeof_rc4_key) const {
        static const byte_t rc4_key[8*1] = {
            0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        };
        sizeof_rc4_key = sizeof(rc4_key);
        return rc4_key;
    }
    virtual const byte_t* test_rc4_iv(size_t& sizeof_rc4_iv) const {
        static const byte_t rc4_iv[8*1] = {
            0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
        };
        sizeof_rc4_iv = sizeof(rc4_iv);
        return rc4_iv;
    }
    virtual const byte_t* test_rc4_plain_text(size_t& sizeof_plain_text) const {
        static const byte_t plain_text[8*3+4] = {
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0,
            0x12, 0x34, 0x56, 0x78,
        };
        sizeof_plain_text = sizeof(plain_text);
        return plain_text;
    }
    virtual const byte_t* test_rc4_cipher_text(size_t& sizeof_cipher_text) const {
        static const byte_t cipher_text[8*3+4] = {
            0x66, 0xa0, 0x94, 0x9f, 0x8a, 0xf7, 0xd6, 0x89,
            0x1f, 0x7f, 0x83, 0x2b, 0xa8, 0x33, 0xc0, 0x0c,
            0x89, 0x2e, 0xbe, 0x30, 0x14, 0x3c, 0xe2, 0x87,
            0x40, 0x01, 0x1e, 0xcf,
        };
        sizeof_cipher_text = sizeof(cipher_text);
        return cipher_text;
    }
    /// ...rc4_key...
    const byte_t* (derives::*rc4_key_)(size_t& sizeof_rc4_key) const;
    virtual const byte_t* rc4_key(size_t& sizeof_rc4_key) const {
        if (rc4_key_) {
            return (this->*rc4_key_)(sizeof_rc4_key);
        }
        return test_rc4_key(sizeof_rc4_key);
    }
    /// ...rc4_iv...
    const byte_t* (derives::*rc4_iv_)(size_t& sizeof_rc4_iv) const;
    virtual const byte_t* rc4_iv(size_t& sizeof_rc4_iv) const {
        if (rc4_iv_) {
            return (this->*rc4_iv_)(sizeof_rc4_iv);
        }
        return test_rc4_iv(sizeof_rc4_iv);
    }
    /// ...rc4_plain_text...
    const byte_t* (derives::*rc4_plain_text_)(const char_t*& chars, size_t& sizeof_rc4_plain_text) const;
    virtual const byte_t* rc4_plain_text(const char_t*& chars, size_t& sizeof_rc4_plain_text) const {
        if (rc4_plain_text_) {
            return (this->*rc4_plain_text_)(chars, sizeof_rc4_plain_text);
        }
        return test_rc4_plain_text(sizeof_rc4_plain_text);
    }
    /// ...rc4_cipher_text...
    const byte_t* (derives::*rc4_cipher_text_)(size_t& sizeof_rc4_cipher_text) const;
    virtual const byte_t* rc4_cipher_text(size_t& sizeof_rc4_cipher_text) const {
        if (rc4_cipher_text_) {
            return (this->*rc4_cipher_text_)(sizeof_rc4_cipher_text);
        }
        return test_rc4_cipher_text(sizeof_rc4_cipher_text);
    }

    /// ...
    /// rc4
    /// 

    /// ...on...option...
    virtual int on_aes_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if (!(err = set_aes_cipher_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_des3_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if (!(err = set_des3_cipher_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    /// ...on...option...
    virtual int on_rc4_cipher_algorithm_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        if (!(err = set_rc4_cipher_run(argc, argv, env))) {
        } else {
        }
        return err;
    }

protected:
    cipher_algorithm_t cipher_algorithm_;
}; /// class maint
typedef maint<> main;

} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_HPP
