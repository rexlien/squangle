// Copyright 2004-present Facebook.  All rights reserved.

#pragma once

#include <wangle/client/ssl/SSLSession.h>

namespace folly {
class SSLContext;
}

namespace facebook {
namespace common {
namespace mysql_client {

/* Interface for an SSL connection options Provider */
class SSLOptionsProviderBase {
 public:
  virtual ~SSLOptionsProviderBase() {}

  // The SSL Context and Session options to be set for the connection
  virtual std::shared_ptr<folly::SSLContext> getSSLContext() = 0;

  // The CRYPTO reference count for the session should already be incremented.
  // Libmysqlclient layer will take ownership of the session and free it when
  // connection succeeds or fails.
  virtual SSL_SESSION* getSSLSession() = 0;

  // this function is called when an SSL connection is successfully established
  virtual void storeSSLSession(wangle::SSLSessionPtr ssl_session) = 0;
};
}
}
}
