/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

/*
 * Copyright (c) 2017 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Base/API.h>
#include <Swiften/Parser/GenericPayloadParserFactory.h>
#include <Swiften/Parser/PayloadParsers/MIXSetNickParser.h>

namespace Swift {
    class SWIFTEN_API MIXSetNickParserFactory : public PayloadParserFactory {
        public:
            MIXSetNickParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const override {
                return element == "setnick" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() override {
                return new MIXSetNickParser();
            }
    };
}
