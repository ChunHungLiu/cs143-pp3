/** @file ast_scope.cc
 *  @brief define scope 
 * 
 *  @author Chen Chen
 *  @bug no known bugs
 */

#include "ast_scope.h"




Scope::Scope()
{

  htable = new Hashtable<Decl *>();
  parents = new List<Scope *>();

}

Node *Scope::Lookup(const char *key, bool recursive)
{
  Decl *n = htable->Lookup(key);
  if(n){ 
    return n; 
  } else { 
    if(parent = NULL || !recursive )
      return NULL; 
    else{
      /* recursively query all parent scopes */
      for (int i = 0; i < parents->NumElements(); i++){
	n = parents->Nth(i)->Lookup(key);
	if(n)
	  return n;
      }
      return NULL;
    }
  }
}


void Scope::AddParentScope(Scope *p)
{
  Assert(p!=NULL);
  parents->Append(p);
  return;
}
