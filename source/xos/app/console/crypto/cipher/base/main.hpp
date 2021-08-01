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
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP

#include "xos/app/console/crypto/cipher/base/main_opt.hpp"

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_IVSIZE 1
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_IVSIZE*1024)

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_KEYSIZE 2
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_KEYSIZE*1024)

#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE 64
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE \
    (XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KB_BLOCKSIZE*1024)

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace base {

/// class maint
template 
<class TExtends = main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

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
    maint()
    : cipher_iv_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE), 
      cipher_key_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE), 
      cipher_test_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE), 
      encipher_text_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE), 
      decipher_text_size_(XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE) {
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

    /// ...plain_run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_encipher_run(argc, argv, env);
        return err;
    }
    /// ...cipher_run
    virtual int cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->all_decipher_run(argc, argv, env);
        return err;
    }
    virtual int on_cipher_text_set(const char_t* to) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;

        if ((chars = this->cipher_text(length))) {
            const string_t& cipher_text = this->cipher_text_string();
            string_reader_t cipher_reader(cipher_text);
            byte_t* encipher_text = 0;
            size_t sizeof_encipher_text = 0;

            if ((encipher_text = this->encipher_text(sizeof_encipher_text))) {
                ssize_t count = 0;

                if (0 < (count = this->input_x(encipher_text, sizeof_encipher_text, cipher_reader))) {

                    this->set_encipher_text_size(count);
                    if (!(err = this->on_encipher_text_set(encipher_text, sizeof_encipher_text, count))) {
                        const byte_t* cipher_test = 0;
                        size_t sizeof_cipher_test = 0;

                        this->set_cipher_test(encipher_text, count);
                        if ((cipher_test = this->cipher_test(sizeof_cipher_test))) {
                            err = this->on_cipher_test_set(cipher_test, sizeof_cipher_test, count);
                        }
                    }
                }
            }
        }
        return err;
    }

    /// on_set_key_option
    virtual int on_set_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const string_t cipher_key_text(optarg);
            string_reader_t cipher_reader(cipher_key_text);
            byte_t* cipher_key = 0;
            size_t sizeof_cipher_key = 0;

            if ((cipher_key = this->cipher_key_data(sizeof_cipher_key))) {
                ssize_t count = 0;

                if (0 < (count = this->input_x(cipher_key, sizeof_cipher_key, cipher_reader))) {
                    this->set_cipher_key_size(count);
                    err = this->on_cipher_key_set(cipher_key, sizeof_cipher_key, count);
                }
            }
        }
        return err;
    }
    /// on_set_iv_option
    virtual int on_set_iv_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const string_t cipher_iv_text(optarg);
            string_reader_t cipher_reader(cipher_iv_text);
            byte_t* cipher_iv = 0;
            size_t sizeof_cipher_iv = 0;

            if ((cipher_iv = this->cipher_iv_data(sizeof_cipher_iv))) {
                ssize_t count = 0;

                if (0 < (count = this->input_x(cipher_iv, sizeof_cipher_iv, cipher_reader))) {
                    this->set_cipher_iv_size(count);
                    err = this->on_cipher_iv_set(cipher_iv, sizeof_cipher_iv, count);
                }
            }
        }
        return err;
    }

    /// ...cipher_key...
    virtual int on_cipher_key_set
    (byte_t* cipher_key, size_t sizeof_cipher_key, size_t cipher_key_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* cipher_key_data(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key = sizeof(cipher_key_);
        return (byte_t*)cipher_key_;
    }
    virtual byte_t* set_cipher_key_size(size_t sizeof_cipher_key) {
        cipher_key_size_ = sizeof_cipher_key;
        return (byte_t*)cipher_key_;
    }
    virtual const byte_t* cipher_key(size_t& sizeof_cipher_key) const {
        sizeof_cipher_key = sizeof(cipher_key_);
        if ((cipher_key_size_) && (cipher_key_size_ < sizeof_cipher_key)) {
            sizeof_cipher_key = cipher_key_size_;
        }
        return (const byte_t*)cipher_key_;
    }
    
    /// ...cipher_iv...
    virtual int on_cipher_iv_set
    (byte_t* cipher_iv, size_t sizeof_cipher_iv, size_t cipher_iv_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* set_cipher_iv_size(size_t sizeof_cipher_iv) {
        cipher_iv_size_ = sizeof_cipher_iv;
        return (byte_t*)cipher_iv_;
    }
    virtual byte_t* cipher_iv_data(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = sizeof(cipher_iv_);
        return (byte_t*)cipher_iv_;
    }
    virtual const byte_t* cipher_iv(size_t& sizeof_cipher_iv) const {
        sizeof_cipher_iv = sizeof(cipher_iv_);
        if ((cipher_iv_size_) && (cipher_iv_size_ < sizeof_cipher_iv)) {
            sizeof_cipher_iv = cipher_iv_size_;
        }
        return (const byte_t*)cipher_iv_;
    }

    /// ...cipher_test...
    virtual int on_cipher_test_set
    (const byte_t* cipher_test, size_t sizeof_cipher_test, size_t cipher_test_size) {
        int err = 0;
        return err;
    }
    virtual byte_t* set_cipher_test(const byte_t* cipher_test, size_t sizeof_cipher_test) {
        if (0 < (cipher_test_size_ = sizeof_cipher_test)) {
            memcpy(cipher_test_, cipher_test, sizeof_cipher_test);
        }
        return (byte_t*)cipher_test_;
    }
    virtual byte_t* cipher_test_data(size_t& sizeof_cipher_test) const {
        sizeof_cipher_test = sizeof(cipher_test_);
        return (byte_t*)cipher_test_;
    }
    virtual const byte_t* cipher_test(size_t& sizeof_cipher_test) const {
        sizeof_cipher_test = sizeof(cipher_test_);
        if ((cipher_test_size_) && (cipher_test_size_ < sizeof_cipher_test)) {
            sizeof_cipher_test = cipher_test_size_;
        }
        return (const byte_t*)cipher_test_;
    }

    /// ...cipher_text
    virtual int on_encipher_text_set
    (byte_t* encipher_text, size_t sizeof_encipher_text, size_t encipher_text_size) {
        int err = 0;
        return err;
    }
    virtual size_t set_encipher_text_size(size_t to) {
        encipher_text_size_ = to;
        return encipher_text_size_;
    }
    virtual size_t encipher_text_size() const {
        return encipher_text_size_;
    }
    virtual byte_t* encipher_text_data(size_t& sizeof_encipher_text) const {
        sizeof_encipher_text = sizeof(encipher_text_);
        return (byte_t*)encipher_text_;
    }
    virtual byte_t* encipher_text(size_t& sizeof_encipher_text) const {
        sizeof_encipher_text = sizeof(encipher_text_);
        if ((encipher_text_size_) && (encipher_text_size_ < sizeof_encipher_text)) {
            sizeof_encipher_text = encipher_text_size_;
        }
        return (byte_t*)encipher_text_;
    }
    virtual byte_t* decipher_text(size_t& sizeof_decipher_text) const {
        sizeof_decipher_text = sizeof(decipher_text_);
        return (byte_t*)decipher_text_;
    }

protected:
    size_t cipher_iv_size_, cipher_key_size_, 
           cipher_test_size_, encipher_text_size_, decipher_text_size_;

    byte_t cipher_iv_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_IVSIZE],
           cipher_key_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_KEYSIZE],
           cipher_test_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE],
           encipher_text_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE],
           decipher_text_[XOS_APP_CONSOLE_CRYPTO_CIPHER_MAIN_BLOCKSIZE];
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_BASE_MAIN_HPP
