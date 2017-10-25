#pragma once

typedef uint64_t AgentId;

class Agent : public cmn::CanLog {
public:
	Agent(AgentId id, std::string name) : id(id), CanLog(name) {
	}

protected:
	AgentId id;
};

