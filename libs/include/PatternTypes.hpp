#pragma once

#include "Pattern.hpp"

#include "json.hpp"

class PatternTypes
{
public:
  PatternTypes()=default;
  PatternTypes(const G4String& type);
  void setJsonFile(const nlohmann::json& json);
  void buildTypes();
  bool hasType(const G4String& name);
  Pattern& operator[](const G4String& name){return m_Pattern[name];}
  std::map<std::string,Pattern>::iterator begin(){return m_Pattern.begin();}
  std::map<std::string,Pattern>::iterator end(){return m_Pattern.end();}
private:
  void verifyParameters();
  nlohmann::json m_Json{};
  nlohmann::json m_JsonTypes{};
  G4String m_Type{""};
  std::map<std::string,Pattern> m_Pattern;
};

using PatternTypesIterator=std::map<std::string,Pattern>::iterator;
