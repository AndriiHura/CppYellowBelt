#pragma once

#include<string>
#include<vector>
#include<memory>
#include "date.h"


using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual,
};

enum class LogicalOperation {
	Or, 
	And
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
private:
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date, const string& event) const override;
private:
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date& date);

	 bool Evaluate(const Date& date, const string& event) const override;

private:
	const Comparison cmp_;
	const Date date_;

	

};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const string& event_in);

	 bool Evaluate(const Date& date, const string& event) const override;

private:
	const string event_;
	const Comparison cmp_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation logOp, const shared_ptr<Node> lhs, const shared_ptr<Node> rhs);

	 bool Evaluate(const Date& date, const string& event) const override;

private:
	const LogicalOperation logOp_;
	const shared_ptr<Node> lhs_;
	const shared_ptr<Node> rhs_;
};

