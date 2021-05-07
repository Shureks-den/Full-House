#pragma once

#include <string>

#include <boost/property_tree/ptree.hpp>

class MsgFabric {
 public:
    virtual ~MsgFabric() = 0;
 protected:
    static std::string MsgFromPtree(boost::property_tree::ptree const &request);
};

class MsgClient : public MsgFabric {
 public:
    static std::string Autorisation(std::string const &login, std::string const &password);
    static std::string Logout();
    static std::string Ping();
    static std::string Disconnect();

    static std::string CreateRoom(std::string const &password);
    static std::string CreateRoomReault();

    static std::string JoinRoom(uint64_t const &id, std::string const &password);
    static std::string JoinRoomReault();

    static std::string LeaveRoom();

    static std::string StartGame();

    static std::string GameRaise();
    static std::string GameCold();
    static std::string GameFlow();
    static std::string GameBet();
    static std::string GameSkip();
};

class MsgServer : public MsgFabric {
 public:
    static std::string AutorisationDone();
    static std::string AutorisationFaild();

    static std::string Logout();
    static std::string Ping();
    static std::string Error();
    static std::string Disconnect();

    static std::string CreateRoomOn();
    static std::string CreateRoomDone(uint64_t const &id, std::string const &password);
    static std::string CreateRoomFailed();

    static std::string JoinRoomOn(uint64_t const &id);
    static std::string JoinRoomDone(uint64_t const &id);
    static std::string JoinRoomFaild(uint64_t const &id);

    static std::string LeaveRoomDone();
    static std::string LeaveRoomFailed();

    static std::string StartGameDone();
    static std::string StartGameFailed();

    static std::string GameStatus();
};
