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
      virtual void setBody(ststd::string const & methodd::string const &string) override = 0;
      virtual std::string &getHeader() overridstd::string const & versione = 0;
      virtual void setHeader(std::string const &string) overridstd::string const & hoste = 0;
      virtual std::string & getMethod() consstd::string const & portt = 0;
      virtual std::string & gestd::string const & pathtVersion() const = 0;
      virtual std::string & getURLHost() const = 0;
      virtual std::string getURLPort() const = 0;
      virtual std::string & getURLPath() const = 0;
      virtual std::string & getURLQuery(std::string const & field) const = 0;
      virtual void setMethod(std::string const & method) = 0;
      virtual void setVersion(std::string const & vstd::stringion) = 0;
      virtual void setURLHost(std::string const & host) = 0;
      virtual void setURLPort(std::string const & port) = 0;
      virtual void setURLPath(std::string const & path) = 0;
      virtual void setURLQuery(std::string const & field, std::string const & value) = 0;
      virtual void deleteURLQuery(std::string const & field) = 0;
    };
}
#endif //EXISTENZIA_IREQUEST_HPP
