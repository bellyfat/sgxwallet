/**
 * This file is generated by jsonrpcstub, DO NOT CHANGE IT MANUALLY!
 */

#ifndef JSONRPC_CPP_STUB_STUBCLIENT_H_
#define JSONRPC_CPP_STUB_STUBCLIENT_H_

#include <jsonrpccpp/client.h>

class StubClient : public jsonrpc::Client
{
    public:
        StubClient(jsonrpc::IClientConnector &conn, jsonrpc::clientVersion_t type = jsonrpc::JSONRPC_CLIENT_V2) : jsonrpc::Client(conn, type) {}

        Json::Value importBLSKeyShare(int index, const std::string& keyShare, const std::string& keyShareName, int n, int t) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["index"] = index;
            p["keyShare"] = keyShare;
            p["keyShareName"] = keyShareName;
            p["n"] = n;
            p["t"] = t;
            Json::Value result = this->CallMethod("importBLSKeyShare",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value blsSignMessageHash(const std::string& keyShareName, const std::string& messageHash, int n, int signerIndex, int t) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["keyShareName"] = keyShareName;
            p["messageHash"] = messageHash;
            p["n"] = n;
            p["signerIndex"] = signerIndex;
            p["t"] = t;
            Json::Value result = this->CallMethod("blsSignMessageHash",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value importECDSAKey(const std::string& key, const std::string& keyName) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["key"] = key;
            p["keyName"] = keyName;
            Json::Value result = this->CallMethod("importECDSAKey",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value generateECDSAKey(const std::string& keyName) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["keyName"] = keyName;
            Json::Value result = this->CallMethod("generateECDSAKey",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value getPublicECDSAKey(const std::string& keyName) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["keyName"] = keyName;
            Json::Value result = this->CallMethod("getPublicECDSAKey",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value ecdsaSignMessageHash(int base, const std::string& keyName, const std::string& messageHash) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["base"] = base;
            p["keyName"] = keyName;
            p["messageHash"] = messageHash;
            Json::Value result = this->CallMethod("ecdsaSignMessageHash",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value generateDKGPoly(const std::string& polyName, int t) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["polyName"] = polyName;
            p["t"] = t;
            Json::Value result = this->CallMethod("generateDKGPoly",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
        Json::Value getVerificationVector(const std::string& polyName, int n, int t) throw (jsonrpc::JsonRpcException)
        {
            Json::Value p;
            p["polyName"] = polyName;
            p["n"] = n;
            p["t"] = t;
            Json::Value result = this->CallMethod("getVerificationVector",p);
            if (result.isObject())
                return result;
            else
                throw jsonrpc::JsonRpcException(jsonrpc::Errors::ERROR_CLIENT_INVALID_RESPONSE, result.toStyledString());
        }
};

#endif //JSONRPC_CPP_STUB_STUBCLIENT_H_
