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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 2/7/2021, 9/17/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPT_HPP

#include "xos/app/console/crypto/base/main.hpp"
#include "xos/crypto/hash/algorithm.hpp"
#include "xos/io/crt/file/reader.hpp"

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPT "hash"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTUSE "simple hash"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_S "h::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_C 'h'
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPT "merkel"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTUSE "merkel hash"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPT "key"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG ""
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTUSE "hmac key"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_S "k::"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_C 'k'
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTION \
   {XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG_RESULT, \
    XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_C}, \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTVAL_S \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTVAL_S \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTION \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTION \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_PLAIN_OPTION \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_BASE64_OPTION \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_UPPER_OPTION \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_LOWER_OPTION \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_NO_LINE_OPTION \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_CHARS_BASE \

#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_CRYPTO_BASE_MAIN_OPTIONS_OPTIONS_BASE \
   
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGS "[source]"
#define XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGV "[source] hash source",

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {
namespace base {

/// class main_optt
template 
<class TExtends = crypto::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt(): run_(0), hash_run_(0), hash_initialize_(0), hash_finalize_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

protected:
    /// ...default_run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            const char_t* arg = 0;
            if ((argc > optind) && (arg = argv[optind]) && (arg[0])) {
                err = this->all_hash_run(argc, argv, env);
            } else {
                err = extends::default_run(argc, argv, env);
            }
        }
        return err;
    }

    /// ...plain_run
    virtual int plain_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = all_hash_run(argc, argv, env);
        return err;
    }

    /// ...get_hmac_key_run
    virtual int get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* hmac_key = 0;
        size_t sizeof_hmac_key = 0;

        if ((hmac_key = this->hmac_key(sizeof_hmac_key))) {
            this->output_x(hmac_key, sizeof_hmac_key);
        }
        return err;
    }
    virtual int before_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_get_hmac_key_run(argc, argv, env))) {
            int err2 = 0;
            err = get_hmac_key_run(argc, argv, env);
            if ((err2 = after_get_hmac_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_get_hmac_key_run;
        return err;
    }
    virtual int before_set_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_get_hmac_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_get_hmac_key_run(argc, argv, env))) {
            int err2 = 0;
            err = set_get_hmac_key_run(argc, argv, env);
            if ((err2 = after_set_get_hmac_key_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_run
    int (derives::*hash_run_)(int argc, char_t** argv, char_t** env);
    virtual int hash_run(int argc, char_t** argv, char_t** env) {
        xos::crypto::hash::algorithm* this_hash_algorithm = 0;
        int err = 1;

        if ((this_hash_algorithm = this->hash_algorithm())) {
            xos::crypto::hash::algorithm& algorithm = *this_hash_algorithm;
            const char_t* arg = 0;

            if ((argc > optind) && (arg = argv[optind]) && (arg[0])) {
                err = this->all_hash_source(algorithm, arg);
            } else {
                const char_t* chars = 0; size_t length = 0;
    
                if ((chars = this->plain_text(length)) && (0 < length)) {
                    LOGGER_LOG_DEBUG("...\"" << chars << "\" = plain_text(length = " << length << ")");
                    err = this->all_hash_chars(algorithm, chars, length);
                } else {
                    err = this->all_hash_chars(algorithm, 0,0);
                }
            }
        }
        return err;
    }
    virtual int before_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_run(argc, argv, env))) {
            int err2 = 0;
            err = hash_run(argc, argv, env);
            if ((err2 = after_hash_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_run_ = &derives::all_hash_run;
        return err;
    }
    virtual int before_set_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_hash_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_hash_run(argc, argv, env))) {
            int err2 = 0;
            err = set_hash_run(argc, argv, env);
            if ((err2 = after_set_hash_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, const char_t* location) {
        int err = 1;
        const char_t* chars = 0;
        
        if ((chars = location) && (chars[0])) {
            io::crt::file::reader source;

            LOGGER_LOG_DEBUG("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                LOGGER_LOG_DEBUG("...source.open(chars = \"" << chars << "\")");

                err = this->all_hash_source(hash, source);

                LOGGER_LOG_DEBUG("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOGGER_LOG_DEBUG("...source.close() \"" << chars << "\"");
                } else {
                    LOGGER_LOG_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOGGER_LOG_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        }
        return err;
    }
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location) {
        int err = 0;
        if (!(err = before_hash_source(hash, location))) {
            int err2 = 0;
            err = hash_source(hash, location);
            if ((err2 = after_hash_source(hash, location))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, io::reader& source) {
        int err = 1;
        size_t size = 0;
        byte_t *block = 0;
        
        if ((block = this->set_block_to_size(size))) {
            err = this->all_hash_source(hash, block, size, source);
        }
        return err;
    }
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source) {
        int err = 0;
        if (!(err = before_hash_source(hash, source))) {
            int err2 = 0;
            err = hash_source(hash, source);
            if ((err2 = after_hash_source(hash, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source) {
        int err = 1;
        ssize_t hashsize = 0;
        size_t blockcount = 0, dots = 0;
        time_t t1 = 0, t2 = 0, t = 1;

        if ((0 < (hashsize = hash.hashsize())) && (!(err = this->all_hash_initialize(hash)))) {

            err = 0;
            ::time(&t1);
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount, ++blockcount) {

                if (0 < (amount = source.read(block, blocksize))) {
                    if (amount != (hash.hash(block, amount))) {
                        err = 1;
                    } else {
                        ::time(&t2);
                        if ((t2 - t1) >= t) {
                            t1 = t2;
                            ++dots;
                            this->err(".", 1);
                            LOGGER_LOG_DEBUG("..." << (blockcount+1) << " blocks read");
                        }
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                if (!(err)) {
                    if (dots) {
                        this->errln();
                    }
                    err = this->hash_finalize(hash, hashsize, block, blocksize);
                }
                break;
            }
            if (!(err)) {
                LOGGER_LOG_DEBUG("..." << (blockcount+1) << " blocks read");
            }
        }
        return err;
    }
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source) {
        int err = 0;
        if (!(err = before_hash_source(hash, block, blocksize, source))) {
            int err2 = 0;
            err = hash_source(hash, block, blocksize, source);
            if ((err2 = after_hash_source(hash, block, blocksize, source))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_chars
    virtual int hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length) {
        int err = 1;
        ssize_t hashsize = 0;

        if ((0 < (hashsize = hash.hashsize()))) {
            byte_t *block = 0; size_t blocksize = 0;

            if ((block = this->hash(blocksize)) && (hashsize <= (blocksize))) {

                err = this->hash_chars(hash, hashsize, block, hashsize, source, length);
            }
        }
        return err;
    }
    virtual int before_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length) {
        int err = 0;
        if (!(err = before_hash_chars(hash, source, length))) {
            int err2 = 0;
            err = hash_chars(hash, source, length);
            if ((err2 = after_hash_chars(hash, source, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...hash_chars
    virtual int hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length) {
        int err = 1;

        if ((block) && (blocksize)) {

            if (!(err = (this->all_hash_initialize(hash)))) {
                ssize_t count = 0;
    
                if ((source) && (length)) {
                    LOGGER_LOG_DEBUG("hash.hash(source = \"" << string_t(source, length) << "\", length = " << length << ")...");
                    if (length != (hash.hash(source, length))) {
                        return err = 1;
                    }
                }
                err = this->all_hash_finalize(hash, hashsize, block, blocksize);
            }
        }
        return err;
    }
    virtual int before_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length) {
        int err = 0;
        if (!(err = before_hash_chars(hash, hashsize, block, blocksize, source, length))) {
            int err2 = 0;
            err = hash_chars(hash, hashsize, block, blocksize, source, length);
            if ((err2 = after_hash_chars(hash, hashsize, block, blocksize, source, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_initialize
    int (derives::*hash_initialize_)(xos::crypto::hash::algorithm& hash);
    virtual int hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        if ((this->hash_initialize_)) {
            err = (this->*hash_initialize_)(hash);
        } else {
            err = this->all_simple_hash_initialize(hash);            
        }
        return err;
    }
    virtual int before_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int after_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int all_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        if (!(err = before_hash_initialize(hash))) {
            int err2 = 0;
            err = hash_initialize(hash);
            if ((err2 = after_hash_initialize(hash))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...simple_hash_initialize
    virtual int simple_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        if (0 > hash.initialize()) {
            err = 1;
        }
        return err;
    }
    virtual int before_simple_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int after_simple_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int all_simple_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        if (!(err = before_simple_hash_initialize(hash))) {
            int err2 = 0;
            err = simple_hash_initialize(hash);
            if ((err2 = after_simple_hash_initialize(hash))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...hmac_hash_initialize
    virtual int hmac_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 1;
        const byte_t* hmac_key = 0;
        size_t sizeof_hmac_key = 0;

        if ((hmac_key = this->hmac_key(sizeof_hmac_key))) {
            if (0 <= hash.initialize(hmac_key, sizeof_hmac_key)) {
                err = 0;
            }
        } else {
        }
        return err;
    }
    virtual int before_hmac_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int after_hmac_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        return err;
    }
    virtual int all_hmac_hash_initialize(xos::crypto::hash::algorithm& hash) {
        int err = 0;
        if (!(err = before_hmac_hash_initialize(hash))) {
            int err2 = 0;
            err = hmac_hash_initialize(hash);
            if ((err2 = after_hmac_hash_initialize(hash))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_hmac_hash_initialize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_initialize_ = &derives::all_hmac_hash_initialize;
        return err;
    }
    virtual int before_set_hmac_hash_initialize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_hmac_hash_initialize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_hmac_hash_initialize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_hmac_hash_initialize(argc, argv, env))) {
            int err2 = 0;
            err = set_hmac_hash_initialize(argc, argv, env);
            if ((err2 = after_set_hmac_hash_initialize(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_finalize
    int (derives::*hash_finalize_)(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize);
    virtual int hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        if ((this->hash_finalize_)) {
            err = (this->*hash_finalize_)(hash, hashsize, block, blocksize);
        } else {
            err = this->all_simple_hash_finalize(hash, hashsize, block, blocksize);            
        }
        return err;
    }
    virtual int before_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int after_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int all_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        if (!(err = before_hash_finalize(hash, hashsize, block, blocksize))) {
            int err2 = 0;
            err = hash_finalize(hash, hashsize, block, blocksize);
            if ((err2 = after_hash_finalize(hash, hashsize, block, blocksize))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...simple_hash_finalize
    virtual int simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                this->output_hash(block, count);
                err = 0;
            }
        }
        return err;
    }
    virtual int before_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int after_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int all_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        if (!(err = before_simple_hash_finalize(hash, hashsize, block, blocksize))) {
            int err2 = 0;
            err = simple_hash_finalize(hash, hashsize, block, blocksize);
            if ((err2 = after_simple_hash_finalize(hash, hashsize, block, blocksize))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_simple_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_finalize_ = &derives::all_simple_hash_finalize;
        return err;
    }
    virtual int before_set_simple_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_simple_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_simple_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_simple_hash_finalize(argc, argv, env))) {
            int err2 = 0;
            err = set_simple_hash_finalize(argc, argv, env);
            if ((err2 = after_set_simple_hash_finalize(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...merkel_hash_finalize
    virtual int merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");

                if ((0 <= (hash.initialize()))) {

                    if (count == (hash.hash(block, count))) {
    
                        if (hashsize == (count = hash.finalize(block, hashsize))) {
                            LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                            this->output_hash(block, count);
                            err = 0;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int before_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int after_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        return err;
    }
    virtual int all_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        if (!(err = before_merkel_hash_finalize(hash, hashsize, block, blocksize))) {
            int err2 = 0;
            err = merkel_hash_finalize(hash, hashsize, block, blocksize);
            if ((err2 = after_merkel_hash_finalize(hash, hashsize, block, blocksize))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_merkel_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        hash_finalize_ = &derives::all_merkel_hash_finalize;
        return err;
    }
    virtual int before_set_merkel_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_merkel_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_merkel_hash_finalize(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_merkel_hash_finalize(argc, argv, env))) {
            int err2 = 0;
            err = set_merkel_hash_finalize(argc, argv, env);
            if ((err2 = after_set_merkel_hash_finalize(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...output_hash
    virtual int output_hash(const void* block, size_t length) {
        int err = 0;
        err = this->output_x(block, length);
        return err;
    }
    virtual int before_output_hash(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int after_output_hash(const void* block, size_t length) {
        int err = 0;
        return err;
    }
    virtual int all_output_hash(const void* block, size_t length) {
        int err = 0;
        if (!(err = before_output_hash(block, length))) {
            int err2 = 0;
            err = output_hash(block, length);
            if ((err2 = after_output_hash(block, length))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_algorithm
    virtual xos::crypto::hash::algorithm* set_hash_algorithm(xos::crypto::hash::algorithm* to) {
        return hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm* hash_algorithm() const {
        return 0;
    }

    /// ...hmac_key...
    virtual const byte_t* hmac_key(size_t& size) const {
        size = 0;
        return 0;
    }

    /// ...hash...
    virtual byte_t* hash(size_t& size) const {
        size = 0;
        return 0;
    }

    /// ...block...
    virtual byte_t* set_block_to_size(size_t& size) {
        size = 0;
        return 0;
    }
    virtual size_t set_block_size(size_t to) {
        return block_size();
    }
    virtual size_t block_size() const {
        return 0;
    }

    /// ...option...
    virtual int on_hash_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_simple_hash_finalize(argc, argv, env))) {
            if (!(err = this->all_set_hash_run(argc, argv, env))) {
                err = this->all_set_plain_run(argc, argv, env);
            }
        }
        return err;
    }
    virtual int on_merkel_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_merkel_hash_finalize(argc, argv, env))) {
            if (!(err = this->all_set_hash_run(argc, argv, env))) {
                err = this->all_set_plain_run(argc, argv, env);
            }
        }
        return err;
    }
    virtual int on_hmac_key_set
    (byte_t* hmac_key, size_t sizeof_hmac_key, size_t hmac_key_size,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_hmac_hash_initialize(argc, argv, env))) {
        }
        return err;
    }
    virtual int on_set_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_get_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_key_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            if (!(err = this->all_set_get_hmac_key_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_key_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            err = this->on_set_key_option(optval, optarg, optname, optind, argc, argv, env);
        } else {
            err = this->on_get_key_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname, 
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_C:
            err = this->on_hash_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_C:
            err = this->on_merkel_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_C:
            err = this->on_key_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_HASH_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_MERKEL_OPTUSE;
            break;
        case XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTARG;
            chars = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_KEY_OPTUSE;
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace base
} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_BASE_MAIN_OPT_HPP
