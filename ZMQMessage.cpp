/*
    Copyright (C) 2020 SKALE Labs

    This file is part of skale-consensus.

    skale-consensus is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    skale-consensus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with skale-consensus.  If not, see <https://www.gnu.org/licenses/>.

    @file ZMQMessage.cpp
    @author Stan Kladko
    @date 2020
*/

#include "common.h"

#include "BLSSignReqMessage.h"
#include "ECDSASignReqMessage.h"
#include "ZMQMessage.h"



uint64_t ZMQMessage::getUint64Rapid(const char *_name) {
    CHECK_STATE(_name);
    CHECK_STATE(d->HasMember(_name));
    const rapidjson::Value& a = (*d)[_name];
    CHECK_STATE(a.IsUint64());
    return a.GetUint64();
};

string ZMQMessage::getStringRapid(const char *_name) {
    CHECK_STATE(_name);
    CHECK_STATE(d->HasMember(_name));
    CHECK_STATE((*d)[_name].IsString());
    return (*d)[_name].GetString();
};

shared_ptr<ZMQMessage> ZMQMessage::parse(vector<uint8_t>& _msg) {

    CHECK_STATE(_msg.at(_msg.size() - 1) == 0);

    auto d = make_shared<rapidjson::Document>();

    d->Parse((const char*) _msg.data());

    CHECK_STATE(!d->HasParseError());
    CHECK_STATE(d->IsObject())

    CHECK_STATE(d->HasMember("type"));
    CHECK_STATE((*d)["type"].IsString());
    auto type =  (*d)["type"].GetString();

    shared_ptr<ZMQMessage> result;

    if (type == ZMQMessage::BLS_SIGN_REQ) {
        result = make_shared<BLSSignReqMessage>(d);
    } else if (type == ZMQMessage::ECDSA_SIGN_REQ) {
        result = make_shared<ECDSASignReqMessage>(d);
    } else {
        throw SGXException(-301, "Incorrect zmq message type: " + string(type));
    }

    return result;

}
