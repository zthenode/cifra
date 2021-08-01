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
///   Date: 5/1/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CIFRA_MAIN_HPP
#define XOS_APP_CONSOLE_CIFRA_MAIN_HPP

#include "xos/app/console/cifra/main_opt.hpp"

#if defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)
#include "xos/crypto/hash/openssl/md5.hpp"
#include "xos/crypto/hash/openssl/sha1.hpp"
#include "xos/crypto/hash/openssl/sha256.hpp"
#include "xos/crypto/hash/openssl/sha512.hpp"
#endif /// defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)

namespace xos {
namespace app {
namespace console {
namespace cifra {

/// class maint
template <class TExtends = main_opt, class TImplements = typename TExtends::implements>
class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

#if defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)
    enum { HASHSIZE = xos::crypto::hash::sha512::HASHSIZE };
#endif /// defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    maint() {
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw xos::exception(exception_unexpected);
    }
public:

#if defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)
protected:
    /// md5 / sha...
    virtual xos::crypto::hash::md5& md5() const {
        return (xos::crypto::hash::md5&)openssl_md5_;
    }
    virtual xos::crypto::hash::sha1& sha1() const {
        return (xos::crypto::hash::sha1&)openssl_sha1_;
    }
    virtual xos::crypto::hash::sha256& sha256() const {
        return (xos::crypto::hash::sha256&)openssl_sha256_;
    }
    virtual xos::crypto::hash::sha512& sha512() const {
        return (xos::crypto::hash::sha512&)openssl_sha512_;
    }

protected:
    xos::crypto::hash::openssl::md5 openssl_md5_;
    xos::crypto::hash::openssl::sha1 openssl_sha1_;
    xos::crypto::hash::openssl::sha256 openssl_sha256_;
    xos::crypto::hash::openssl::sha512 openssl_sha512_;
#endif /// defined(XOS_APP_CONSOLE_CIFRA_MAIN_OPT_EXTENDS_HASH_MAIN)
}; /// class maint
typedef maint<> main;

} /// namespace cifra
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CIFRA_MAIN_HPP 
