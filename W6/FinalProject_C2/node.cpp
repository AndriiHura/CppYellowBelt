#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date)
	: cmp_(cmp), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (cmp_ == Comparison::Equal) {
		return date == date_;
	}
	else if (cmp_ == Comparison::Greater) {
		return date > date_;
	}
	else if (cmp_ == Comparison::GreaterOrEqual) {
		return date >= date_;
	}
	else if (cmp_ == Comparison::Less) {
		return date < date_;
	}
	else if (cmp_ == Comparison::LessOrEqual) {
		return date<= date_;
	}
	else if (cmp_ == Comparison::NotEqual) {
		return date != date_;
	}
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event_in)
	: event_(event_in), cmp_(cmp) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
	if (cmp_ == Comparison::Equal) {
		return event == event_;
	}
	else if (cmp_ == Comparison::Greater) {
		return event > event_;
	}
	else if (cmp_ == Comparison::GreaterOrEqual) {
		return event >= event_;
	}
	else if (cmp_ == Comparison::Less) {
		return event < event_;
	}
	else if (cmp_ == Comparison::LessOrEqual) {
		return event <= event_;
	}
	else if (cmp_ == Comparison::NotEqual) {
		return event != event_;
	}
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation logOp,
	const shared_ptr<Node> lhs, const shared_ptr<Node> rhs)
	: logOp_(logOp), lhs_(lhs), rhs_(rhs) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
	if (logOp_ == LogicalOperation::And) {
		return lhs_->Evaluate(date, event) && rhs_->Evaluate(date, event);
	}
	else if (logOp_ == LogicalOperation::Or) {
		return lhs_->Evaluate(date, event) || rhs_->Evaluate(date, event);
	}
}
