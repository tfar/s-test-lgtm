/*
 * Copyright (c) 2013-2017 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <memory>

#include <Swiften/Base/API.h>
#include <Swiften/Elements/PubSubSubscriptions.h>
#include <Swiften/Parser/GenericPayloadParser.h>

namespace Swift {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class SWIFTEN_API PubSubSubscriptionsParser : public GenericPayloadParser<PubSubSubscriptions> {
        public:
            PubSubSubscriptionsParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubSubscriptionsParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}
