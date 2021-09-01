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
///   Date: 1/30/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP

#include "xos/app/console/crypto/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace base {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives; 
    
    typedef typename extends::sequence_t sequence_t;
    typedef typename extends::seeker_t seeker_t;
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
    maint(): input_x_(0), output_x_(0), output_x_ln_(true) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    /// ...plain_run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = plain_text_.has_chars(length))) {
            this->out(chars, length);
            this->outln();
        }
        return err;
    }

    /// ...cipher_run
    virtual int cipher_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = cipher_text_.has_chars(length))) {
            this->out(chars, length);
            this->outln();
        }
        return err;
    }

    /// ...input_x
    ssize_t (derives::*input_x_)(void* block, size_t length, char_reader_t& reader);
    virtual ssize_t base64_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.read64(block, length);
            ///this->outxln(block, count);
        }
        return count;
    }
    virtual ssize_t upper_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
           count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t lower_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((block) && (length)) {
            count = reader.readx(block, length);
        }
        return count;
    }
    virtual ssize_t input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if ((this->input_x_)) {
            count = (this->*input_x_)(block, length, reader);
        } else {
            count = lower_input_x(block, length, reader);
        }
        return count;
    }
    virtual ssize_t before_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t after_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        return count;
    }
    virtual ssize_t all_input_x(void* block, size_t length, char_reader_t& reader) {
        ssize_t count = 0;
        if (0 <= (count = before_input_x(block, length, reader))) {
            ssize_t count2 = 0;
            count = input_x(block, length, reader);
            if (0 > (count2 = after_input_x(block, length, reader))) {
                if (0 <= (count)) count = count2;
            }
        }
        return count;
    }

    /// ...output_x
    int (derives::*output_x_)(const void* block, size_t length);
    bool output_x_ln_;
    virtual bool set_output_x_ln(bool to = true) {
        output_x_ln_ = to;
        return output_x_ln_;
    }
    virtual bool output_x_ln() const {
        return output_x_ln_;
    }
    virtual int base64_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->out64ln(block, length);
            } else {
                this->out64(block, length);
            }
        }
        return err;
    }
    virtual int upper_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outXln(block, length);
            } else {
                this->outX(block, length);
            }
        }
        return err;
    }
    virtual int lower_output_x(const void* block, size_t length) {
        int err = 0;
        if ((block) && (length)) {
            if (output_x_ln()) {
                this->outxln(block, length);
            } else {
                this->outx(block, length);
            }
        }
        return err;
    }
    virtual int text_output_x(const void* block, size_t length) {
        int err = 0;
        const char_t* chars = 0;
        if ((chars = ((const char_t*)block)) && (length)) {
            if (output_x_ln()) {
                this->outln(chars, length);
            } else {
                this->out(chars, length);
            }
        }
        return err;
    }
    virtual int output_x(const void* block, size_t length) {
        int err = 0;
        if ((this->output_x_)) {
            err = (this->*output_x_)(block, length);
        } else {
            err = lower_output_x(block, length);
        }
        return err;
    }
    virtual int before_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(block, length))) {
            int err2 = 0;
            err = output_x(block, length);
            if ((err2 = after_output_x(block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::base64_input_x;
        output_x_ = &derives::base64_output_x;
        return err;
    }
    virtual int before_set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_base64_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_base64_output_x(argc, argv, env))) {
            int err2 = 0;
            err = set_base64_output_x(argc, argv, env);
            if ((err2 = after_set_base64_output_x(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::upper_input_x;
        output_x_ = &derives::upper_output_x;
        return err;
    }
    virtual int before_set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_upper_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_upper_output_x(argc, argv, env))) {
            int err2 = 0;
            err = set_upper_output_x(argc, argv, env);
            if ((err2 = after_set_upper_output_x(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_x_ = &derives::lower_input_x;
        output_x_ = &derives::lower_output_x;
        return err;
    }
    virtual int before_set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_lower_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_lower_output_x(argc, argv, env))) {
            int err2 = 0;
            err = set_lower_output_x(argc, argv, env);
            if ((err2 = after_set_lower_output_x(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_x_ = &derives::text_output_x;
        return err;
    }
    virtual int before_set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_text_output_x(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_text_output_x(argc, argv, env))) {
            int err2 = 0;
            err = set_text_output_x(argc, argv, env);
            if ((err2 = after_set_text_output_x(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    virtual int output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if ((chars)) {
            this->outln(chars, length);
        } else {
            err = this->all_output_x(block, length);
        }
        return err;
    }
    virtual int before_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_x(const char_t* chars, const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_x(chars, block, length))) {
            int err2 = 0;
            err = output_x(chars, block, length);
            if ((err2 = after_output_x(chars, block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

protected:
    /// on...option
    virtual int on_test_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_test_run(argc, argv, env);
        return err;
    }
    virtual int on_set_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_plain_text(optarg);
            this->on_plain_text_set(optarg);
            this->set_plain_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_set_cipher_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_cipher_text(optarg);
            this->on_cipher_text_set(optarg);
            this->set_cipher_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_base64_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_base64_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_upper_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_upper_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_lower_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_lower_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_text_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_text_output_x(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_no_line_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_output_x_ln(false);
        return err;
    }

protected:
    /// ...plain... / ...cipher...
    virtual const char_t* set_plain_text(const char_t* to) {
        plain_text_.assign(to);
        return plain_text_.chars();
    }
    virtual const char_t* plain_text(size_t& length) const {
        return plain_text_.has_chars(length);
    }
    virtual const char_t* set_cipher_text(const char_t* to) {
        cipher_text_.assign(to);
        return cipher_text_.chars();
    }
    virtual const char_t* cipher_text(size_t& length) const {
        return cipher_text_.has_chars(length);
    }
    virtual const string_t& cipher_text_string() const {
        return cipher_text_;
    }

protected:
    string_t plain_text_, cipher_text_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_HPP
