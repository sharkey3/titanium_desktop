/*
 * Copyright (c) 2009-2010 Appcelerator, Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HTTPServer_h
#define HTTPServer_h

#include <kroll/kroll.h>
#include <Poco/Exception.h>
#include <Poco/FileStream.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Path.h>
#include <Poco/Thread.h>
#include <Poco/URI.h>

namespace Titanium {

class HTTPServer : public StaticBoundObject {
public:
    HTTPServer();
    virtual ~HTTPServer();

private:    
    static void Run(void*);
    
    void Bind(const ValueList& args, KValueRef result);
    void Close(const ValueList& args, KValueRef result);
    void IsClosed(const ValueList& args, KValueRef result);
    
    void Close();

    KObjectRef global;
    KMethodRef callback;
    std::string ipaddress;
    int port;
    Poco::Thread *thread;
    Poco::Net::ServerSocket *socket;
    Poco::Net::HTTPServer *connection;
};

} // namespace Titanium

#endif
