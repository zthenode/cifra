///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
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
///   Date: 10/6/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP

#include "xos/app/console/crypto/hash/main_opt.hpp"
#include "xos/crypto/hash/openssl/md5.hpp"
#include "xos/crypto/hash/openssl/sha1.hpp"
#include "xos/crypto/hash/openssl/sha256.hpp"
#include "xos/crypto/hash/openssl/sha512.hpp"
/*#include "xos/crypto/hash/md5.hpp"
#include "xos/crypto/hash/sha1.hpp"
#include "xos/crypto/hash/sha256.hpp"
#include "xos/crypto/hash/sha512.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/console/io.hpp"
*/
namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives; 
    
    /*enum { BLOCKSIZE = 1024*64 };
    enum { HASHSIZE = xos::crypto::hash::sha512::HASHSIZE };*/

    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructors / destructor
    maint():/* hash_finalize_(0), *//*output_hash_(0),*/
        md5_hash_algorithm_(0), sha1_hash_algorithm_(0), sha256_hash_algorithm_(0), sha512_hash_algorithm_(0)
        /*, block_size_(BLOCKSIZE)*/ {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    /*/// ...default_run
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* arg = 0;
        if ((argc > optind) && (arg = argv[optind]) && (arg[0])) {
            err = this->all_hash_run(argc, argv, env);
        } else {
            err = extends::default_run(argc, argv, env);
        }
        return err;
    }*/

    /*/// ...version_run
    virtual int after_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = this->usage(argc, argv, env);
        return err;
    }*/

    /*/// ...hash_run
    virtual int hash_run(int argc, char_t** argv, char_t** env) {
        xos::crypto::hash::algorithm& algorithm = this->hash_algorithm();
        const char_t* arg = 0;
        int err = 0;

        if ((argc > optind) && (arg = argv[optind]) && (arg[0])) {
            err = this->all_hash_source(algorithm, arg, argc, argv, env);
        } else {
            const char_t* chars = 0; size_t length = 0;

            if ((chars = this->plain_text(length)) && (0 < length)) {
                LOGGER_LOG_DEBUG("...\"" << chars << "\" = plain_text(length = " << length << ")");
                err = this->hash_chars(algorithm, chars, length, argc, argv, env);
            } else {
                err = this->hash_chars(algorithm, 0,0, argc, argv, env);
            }
        }
        return err;
    }

    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, const char_t* location, int argc, char_t** argv, char_t** env) {
        int err = 1;
        const char_t* chars = 0;
        
        if ((chars = location) && (chars[0])) {
            io::crt::file::reader source;

            LOGGER_LOG_DEBUG("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                LOGGER_LOG_DEBUG("...source.open(chars = \"" << chars << "\")");

                err = this->all_hash_source(hash, source, argc, argv, env);

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
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, const char_t* location, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_source(hash, location, argc, argv, env))) {
            int err2 = 0;
            err = hash_source(hash, location, argc, argv, env);
            if ((err2 = after_hash_source(hash, location, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 1;
        size_t size = 0;
        byte_t *block = 0;
        
        if ((block = this->set_block_to_size(size))) {
            err = this->all_hash_source(hash, block, size, source, argc, argv, env);
        }
        return err;
    }
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_source(hash, source, argc, argv, env))) {
            int err2 = 0;
            err = hash_source(hash, source, argc, argv, env);
            if ((err2 = after_hash_source(hash, source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_source
    virtual int hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 1;
        ssize_t hashsize = 0;
        size_t blockcount = 0, dots = 0;
        time_t t1 = 0, t2 = 0, t = 1;

        if ((0 < (hashsize = hash.hashsize())) && (0 <= (hash.initialize()))) {

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
                    err = this->hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);
                }
                break;
            }
            if (!(err)) {
                LOGGER_LOG_DEBUG("..." << (blockcount+1) << " blocks read");
            }
        }
        return err;
    }
    virtual int before_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_source(xos::crypto::hash::algorithm& hash, byte_t* block, size_t blocksize, io::reader& source, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_source(hash, block, blocksize, source, argc, argv, env))) {
            int err2 = 0;
            err = hash_source(hash, block, blocksize, source, argc, argv, env);
            if ((err2 = after_hash_source(hash, block, blocksize, source, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_chars
    virtual int hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 1;
        ssize_t hashsize = 0;

        if ((0 < (hashsize = hash.hashsize()))) {
            byte_t *block = 0; size_t blocksize = 0;

            if ((block = this->hash(blocksize)) && (hashsize <= (blocksize))) {

                err = this->hash_chars
                (hash, hashsize, block, hashsize, source, length, argc, argv, env);
            }
        }
        return err;
    }
    virtual int before_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_chars(xos::crypto::hash::algorithm& hash, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_chars(hash, source, length, argc, argv, env))) {
            int err2 = 0;
            err = hash_chars(hash, source, length, argc, argv, env);
            if ((err2 = after_hash_chars(hash, source, length, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_chars
    virtual int hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 1;

        if ((block) && (blocksize)) {

            if ((0 <= (hash.initialize()))) {
                ssize_t count = 0;
    
                if ((source) && (length)) {
                    LOGGER_LOG_DEBUG("hash.hash(source = \"" << string_t(source, length) << "\", length = " << length << ")...");
                    if (length != (hash.hash(source, length))) {
                        return err = 1;
                    }
                }
                err = this->all_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);
            }
        }
        return err;
    }
    virtual int before_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_chars(xos::crypto::hash::algorithm& hash, size_t hashsize, byte_t* block, size_t blocksize, const char_t* source, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_chars(hash, hashsize, block, blocksize, source, length, argc, argv, env))) {
            int err2 = 0;
            err = hash_chars(hash, hashsize, block, blocksize, source, length, argc, argv, env);
            if ((err2 = after_hash_chars(hash, hashsize, block, blocksize, source, length, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...hash_finalize
    int (derives::*hash_finalize_)(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env);
    virtual int hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((this->hash_finalize_)) {
            err = (this->*hash_finalize_)(hash, hashsize, block, blocksize, argc, argv, env);
        } else {
            err = this->all_simple_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);            
        }
        return err;
    }
    virtual int before_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
            int err2 = 0;
            err = hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);
            if ((err2 = after_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...simple_hash_finalize
    virtual int simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                this->output_hash(block, count, argc, argv, env);
                err = 0;
            }
        }
        return err;
    }
    virtual int before_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_simple_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_simple_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
            int err2 = 0;
            err = simple_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);
            if ((err2 = after_simple_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
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
    virtual int merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");

                if ((0 <= (hash.initialize()))) {

                    if (count == (hash.hash(block, count))) {
    
                        if (hashsize == (count = hash.finalize(block, hashsize))) {
                            LOGGER_LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                            this->output_hash(block, count, argc, argv, env);
                            err = 0;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual int before_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_merkel_hash_finalize(xos::crypto::hash::algorithm& hash, ssize_t hashsize, byte_t* block, size_t blocksize, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_merkel_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
            int err2 = 0;
            err = merkel_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env);
            if ((err2 = after_merkel_hash_finalize(hash, hashsize, block, blocksize, argc, argv, env))) {
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
*//*
    int (derives::*output_hash_)(const void* block, size_t length, int argc, char_t** argv, char_t** env);
    virtual int upper_output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((block) && (length)) {
            this->outXln(block, length);
        }
        return err;
    }
    virtual int lower_output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((block) && (length)) {
            this->outxln(block, length);
        }
        return err;
    }
*/
/*    virtual int output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
*//*
        if ((this->output_hash_)) {
            err = (this->*output_hash_)(block, length, argc, argv, env);
        } else {
            err = lower_output_hash(block, length, argc, argv, env);
        }
*/
/*        err = this->output_x(block, length);
        return err;
    }
    virtual int before_output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_hash(const void* block, size_t length, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_hash(block, length, argc, argv, env))) {
            int err2 = 0;
            err = output_hash(block, length, argc, argv, env);
            if ((err2 = after_output_hash(block, length, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
*//*
    virtual int set_upper_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hash_ = &derives::upper_output_hash;
        return err;
    }
    virtual int before_set_upper_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_upper_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_upper_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_upper_output_hash(argc, argv, env))) {
            int err2 = 0;
            err = set_upper_output_hash(argc, argv, env);
            if ((err2 = after_set_upper_output_hash(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_lower_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_hash_ = &derives::lower_output_hash;
        return err;
    }
    virtual int before_set_lower_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_set_lower_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_set_lower_output_hash(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_set_lower_output_hash(argc, argv, env))) {
            int err2 = 0;
            err = set_lower_output_hash(argc, argv, env);
            if ((err2 = after_set_lower_output_hash(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
*/

    /*/// on_..._option
    virtual int on_d_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::md5_hash_algorithm;
        err = this->all_set_hash_run(argc, argv, env);
        return err;
    }
    virtual int on_1_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha1_hash_algorithm;
        err = this->all_set_hash_run(argc, argv, env);
        return err;
    }
    virtual int on_2_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha256_hash_algorithm;
        err = this->all_set_hash_run(argc, argv, env);
        return err;
    }
    virtual int on_5_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        hash_algorithm_ = &derives::sha512_hash_algorithm;
        err = this->all_set_hash_run(argc, argv, env);
        return err;
    }*/
/*    virtual int on_hash_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_simple_hash_finalize(argc, argv, env))) {
            err = this->all_set_hash_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_merkel_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_merkel_hash_finalize(argc, argv, env))) {
            err = this->all_set_hash_run(argc, argv, env);
        }
        return err;
    }
*//*
    virtual int on_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            this->set_plain(optarg);
            err = this->all_set_hash_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_upper_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_upper_output_hash(argc, argv, env))) {
            err = this->all_set_hash_run(argc, argv, env);
        }
        return err;
    }
    virtual int on_lower_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->all_set_lower_output_hash(argc, argv, env))) {
            err = this->all_set_hash_run(argc, argv, env);
        }
        return err;
    }
*/

    /*/// ...hash_algorithm
    xos::crypto::hash::algorithm& (derives::*hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm& hash_algorithm() const {
        if ((this->hash_algorithm_)) {
            return (this->*hash_algorithm_)();
        }
        return default_hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm& default_hash_algorithm() const {
        return sha1_hash_algorithm();
    }
    virtual xos::crypto::hash::algorithm& md5_hash_algorithm() const {
        return md5();
    }
    virtual xos::crypto::hash::algorithm& sha1_hash_algorithm() const {
        return sha1();
    }
    virtual xos::crypto::hash::algorithm& sha256_hash_algorithm() const {
        return sha256();
    }
    virtual xos::crypto::hash::algorithm& sha512_hash_algorithm() const {
        return sha512();
    }
    
    /// md5 / sha...
    virtual xos::crypto::hash::md5& md5() const {
        return (xos::crypto::hash::md5&)md5_;
    }
    virtual xos::crypto::hash::sha1& sha1() const {
        return (xos::crypto::hash::sha1&)sha1_;
    }
    virtual xos::crypto::hash::sha256& sha256() const {
        return (xos::crypto::hash::sha256&)sha256_;
    }
    virtual xos::crypto::hash::sha512& sha512() const {
        return (xos::crypto::hash::sha512&)sha512_;
    }

    virtual byte_t* set_block_to_size(size_t& size) {
        if (0 < (size = block_size())) {
            if (size <= (block_.set_length(size))) {
                return block_.elements();
            }
        }
        return 0;
    }
    virtual size_t set_block_size(size_t to) {
        block_size_ = to;
        return block_size();
    }
    virtual size_t block_size() const {
        return block_size_;
    }
*//*
    virtual const char_t* set_plain(const char_t* to) {
        plain_.assign(to);
        return plain_.chars();
    }
    virtual const char_t* plain(size_t& length) const {
        return plain_.has_chars(length);
    }
*/
/*    virtual byte_t* hash(size_t& size) const {
        size = sizeof(hash_);
        return (byte_t*)&hash_;
    }*/

    /// md5...
    xos::crypto::hash::md5* (derives::*md5_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* md5_hash_algorithm() const {
        if ((md5_hash_algorithm_)) {
            return (this->*md5_hash_algorithm_)();
        }
        return openssl_md5();
    }
    virtual xos::crypto::hash::md5* openssl_md5() const {
        return (xos::crypto::hash::md5*)&openssl_md5_;
    }

    /// sha1...
    xos::crypto::hash::sha1* (derives::*sha1_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha1_hash_algorithm() const {
        if ((sha1_hash_algorithm_)) {
            return (this->*sha1_hash_algorithm_)();
        }
        return openssl_sha1();
    }
    virtual xos::crypto::hash::sha1* openssl_sha1() const {
        return (xos::crypto::hash::sha1*)&openssl_sha1_;
    }

    /// sha256...
    xos::crypto::hash::sha256* (derives::*sha256_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha256_hash_algorithm() const {
        if ((sha256_hash_algorithm_)) {
            return (this->*sha256_hash_algorithm_)();
        }
        return openssl_sha256();
    }
    virtual xos::crypto::hash::sha256* openssl_sha256() const {
        return (xos::crypto::hash::sha256*)&openssl_sha256_;
    }

    /// sha512...
    xos::crypto::hash::sha512* (derives::*sha512_hash_algorithm_)() const;
    virtual xos::crypto::hash::algorithm* sha512_hash_algorithm() const {
        if ((sha512_hash_algorithm_)) {
            return (this->*sha512_hash_algorithm_)();
        }
        return openssl_sha512();
    }
    virtual xos::crypto::hash::sha512* openssl_sha512() const {
        return (xos::crypto::hash::sha512*)&openssl_sha512_;
    }

protected:
    xos::crypto::hash::openssl::md5 openssl_md5_;
    xos::crypto::hash::openssl::sha1 openssl_sha1_;
    xos::crypto::hash::openssl::sha256 openssl_sha256_;
    xos::crypto::hash::openssl::sha512 openssl_sha512_;
/*    size_t block_size_;
    xos::crypto::hash::md5 md5_;
    xos::crypto::hash::sha1 sha1_;
    xos::crypto::hash::sha256 sha256_;
    xos::crypto::hash::sha512 sha512_;
*//*    string_t plain_;
*/
/*    byte_t hash_[HASHSIZE];
    byte_arrayt<BLOCKSIZE> block_;
*/
}; /// class maint
typedef maint<> main;

} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// XOS_APP_CONSOLE_CRYPTO_HASH_MAIN_HPP
