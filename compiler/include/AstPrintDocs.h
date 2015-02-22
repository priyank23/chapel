/*
 * Copyright 2004-2015 Cray Inc.
 * Other additional copyright holders may be indicated within.
 *
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 *
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _AST_PRINT_DOCS_H_
#define _AST_PRINT_DOCS_H_

#include <iostream>
#include <stack>
#include <string>

#include "AstVisitor.h"


class AstPrintDocs : public AstVisitor {
public:
                  AstPrintDocs(std::ostream *file);
  virtual         ~AstPrintDocs();

  //
  // These methods are actually used by this visitor.
  //
  virtual bool   enterAggrType    (AggregateType*     node);
  virtual void   exitAggrType     (AggregateType*     node);
  virtual bool   enterFnSym       (FnSymbol*          node);
  virtual bool   enterModSym      (ModuleSymbol*      node);
  virtual void   exitModSym       (ModuleSymbol*      node);
  virtual void   visitVarSym      (VarSymbol*         node);

  //
  // These methods are _not_ actually used by this visitor, but must be
  // implemented in order to meet the AstVisitor interface.
  //
  virtual bool   enterEnumType    (EnumType*          node);
  virtual void   exitEnumType     (EnumType*          node);

  virtual void   visitPrimType    (PrimitiveType*     node);

  virtual bool   enterArgSym      (ArgSymbol*         node);
  virtual void   exitArgSym       (ArgSymbol*         node);

  virtual void   visitEnumSym     (EnumSymbol*        node);

  virtual void   exitFnSym        (FnSymbol*          node);

  virtual void   visitIpeSym      (IpeSymbol*         node);

  virtual void   visitLabelSym    (LabelSymbol*       node);

  virtual bool   enterTypeSym     (TypeSymbol*        node);
  virtual void   exitTypeSym      (TypeSymbol*        node);

  //
  // The sub-classes of Expr
  //
  virtual bool   enterCallExpr    (CallExpr*          node);
  virtual void   exitCallExpr     (CallExpr*          node);

  virtual bool   enterDefExpr     (DefExpr*           node);
  virtual void   exitDefExpr      (DefExpr*           node);

  virtual bool   enterNamedExpr   (NamedExpr*         node);
  virtual void   exitNamedExpr    (NamedExpr*         node);

  virtual void   visitSymExpr     (SymExpr*           node);

  virtual void   visitUsymExpr    (UnresolvedSymExpr* node);

  //
  // The sub-classes of Stmt
  //
  virtual bool   enterBlockStmt   (BlockStmt*         node);
  virtual void   exitBlockStmt    (BlockStmt*         node);

  virtual bool   enterWhileDoStmt (WhileDoStmt*       node);
  virtual void   exitWhileDoStmt  (WhileDoStmt*       node);

  virtual bool   enterDoWhileStmt (DoWhileStmt*       node);
  virtual void   exitDoWhileStmt  (DoWhileStmt*       node);

  virtual bool   enterCForLoop    (CForLoop*          node);
  virtual void   exitCForLoop     (CForLoop*          node);

  virtual bool   enterForLoop     (ForLoop*           node);
  virtual void   exitForLoop      (ForLoop*           node);

  virtual bool   enterParamForLoop(ParamForLoop*      node);
  virtual void   exitParamForLoop (ParamForLoop*      node);

  virtual bool   enterCondStmt    (CondStmt*          node);
  virtual void   exitCondStmt     (CondStmt*          node);

  virtual void   visitEblockStmt  (ExternBlockStmt*   node);

  virtual bool   enterGotoStmt    (GotoStmt*          node);
  virtual void   exitGotoStmt     (GotoStmt*          node);

private:
  std::ostream*   file;
  unsigned int    tabs;
  std::stack<std::string> moduleNames;
};

#endif
