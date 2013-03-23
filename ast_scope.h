/** @file ast_scope.h
 *  @brief define scope used for scope analysis
 *
 *  @author Chen Chen
 *  @bug no known bugs
 */



#ifndef _H_AST_SCOPE_
#define _H_AST_SCOPE_

#include "ast_decl.h"
#include "list.h"
#include "hashtable.h"

using namespace std;

class Scope
{
 public:
  Scope();
  void Insert(const char *key, Decl *n){htable->Enter(key, n);}
  void Remove(const char *key, Decl *n){htable->Remove(key, n);}
  Node *Lookup(const char *key, bool recursive);
  void AddParentScope(Scope *p);
 protected:
  List<Scope *> *parents;
  Hashtable<Decl *> *htable;

};



#endif /* end of _H_AST_SCOPE_ */
