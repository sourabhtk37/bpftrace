#pragma once

#include <ostream>
#include "ast.h"

namespace ebpf {
namespace bpftrace {
namespace ast {

class Printer : public Visitor {
public:
  explicit Printer(std::ostream &out) : out_(out) { }

  void visit(Integer &integer) override;
  void visit(Variable &var) override;
  void visit(Binop &binop) override;
  void visit(Unop &unop) override;
  void visit(ExprStatement &expr) override;
  void visit(AssignStatement &assignment) override;
  void visit(Probe &probe) override;
  void visit(Program &program) override;

private:
  std::ostream &out_;
};

} // namespace ast
} // namespace bpftrace
} // namespace ebpf