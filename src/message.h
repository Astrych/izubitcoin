// Copyright (c) 2018 reizu
// Distributed under the MIT software license, see the accompanying
// file COPYING or https://opensource.org/licenses/MIT.

#ifndef _IZUBITCOIN_MESSAGE_H
#define _IZUBITCOIN_MESSAGE_H 1

#include "options.h"
#include <string>

using namespace std;

enum Network : uint32_t {
    // https://github.com/Pink2Dev/Pink2/blob/master/src/main.cpp#L3054
    Mainnet = 0xFBF9F4F2,
    // https://github.com/Pink2Dev/Pink2/blob/master/src/main.cpp#L2720
    Testnet = 0x0D050402,

    // Bitcoin Core (BTC)
    MainnetCore = 0xD9B4BEF9,
    TestnetCore = 0x0709110B
};

struct MessageRaw {
    void *content;
    size_t size;
};

struct MessageHeader {
    uint32_t magic;
    char command[12];
    uint32_t payloadLength;
    uint32_t checksum;
} __attribute__ ((__packed__));

class Message {
    public:
        Message(Network network);
        Message(Options *options);
        string getCommandName();
        size_t getPayloadSize();
        u_char *getPayload();
        void setCommandName(string commandName);
        void setPayload(u_char *payload, size_t size);
        uint32_t checksum();
        struct MessageRaw raw();

    protected:
        Network network;
        string commandName;
        u_char *payload;
        size_t payloadSize;
};

#endif
