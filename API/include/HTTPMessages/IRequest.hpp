//
// Created by duhieub on 11/9/17.
//

#ifndef EXISTENZIA_IREQUEST_HPP
#define EXISTENZIA_IREQUEST_HPP

namespace xzia {
    class IMessage;

    class IRequest : IMessage {
      virtual bool hasBody() override = 0;
      virtual std::string &getBody() override = 0;
      virtual void setBody(std::string const &string) override = 0;
      virtual std::string &getHeader() override = 0;
      virtual void setHeader(std::string const &string) override = 0;
      virtual std::string & getMethod() const = 0;
      virtual std::string & getVersion() const = 0;
      virtual std::string & getURLHost() const = 0;
      virtual std::string & getURLPort() const = 0;
      virtual std::string & getURLPath() const = 0;
      virtual std::string & getURLQuery(std::string const & field) const = 0;
      virtual void setMethod() = 0;
      virtual void setVersion() = 0;
      virtual void setURLHost() = 0;
      virtual void setURLPort() = 0;
      virtual void setURLPath() = 0;
      virtual void setURLQuery(std::string const & field, std::string const & value) = 0;
      virtual void deleteURLQuery(std::string const & field) = 0;
    };
}
#endif //EXISTENZIA_IREQUEST_HPP
