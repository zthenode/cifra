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
///   Date: 2/8/2021
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_MD5_MAIN_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_MD5_MAIN_HPP

#include "xos/app/console/crypto/hash/md5/main_opt.hpp"
#include "xos/crypto/hash/openssl/md5.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {
namespace md5 {

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
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint(): md5_algorithm_(0) {
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

    /// md5...
    xos::crypto::hash::md5* (derives::*md5_algorithm_)() const;
    virtual xos::crypto::hash::md5* md5_algorithm() const {
        if ((md5_algorithm_)) {
            return (this->*md5_algorithm_)();
        }
        return openssl_md5();
    }
    virtual xos::crypto::hash::md5* openssl_md5() const {
        return (xos::crypto::hash::md5*)&openssl_md5_;
    }

protected:
    xos::crypto::hash::openssl::md5 openssl_md5_;
}; /// class maint
typedef maint<> main;

} /// namespace md5
} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_MD5_MAIN_HPP
