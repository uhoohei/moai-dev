// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIPARSER_H
#define	MOAIPARSER_H

#include <moaicore/MOAILua.h>

//================================================================//
// MOAIParser
//================================================================//
/**	@name	MOAIParser
	@text	Parses strings using a LALR parser. Generates an
			abstract syntax tree that may then be traversed in Lua.
			
			To use, load a CGT file generated by GOLD Parser Builder.
			Thanks to Devin Cook:
			http://www.devincook.com/goldparser
*/
class MOAIParser :
	virtual public MOAILuaObject {
private:

	USCgt			mCGT;
	USSyntaxNode*	mAST;

	MOAILuaLocal		mOnStartNonterminal;
	MOAILuaLocal		mOnEndNonterminal;
	MOAILuaLocal		mOnTerminal;

	//----------------------------------------------------------------//
	static int		_loadFile				( lua_State* L );
	static int		_loadRules				( lua_State* L );
	static int		_loadString				( lua_State* L );
	static int		_setCallbacks			( lua_State* L );
	static int		_traverse				( lua_State* L );

	//----------------------------------------------------------------//
	void			OnEndNonterminal		( USSyntaxNode* node );
	void			OnStartNonterminal		( USSyntaxNode* node );
	void			OnTerminal				( USSyntaxNode* node );
	void			SetAST					( USSyntaxNode* ast );
	void			Traverse				( USSyntaxNode* node );

public:
	
	DECL_LUA_FACTORY ( MOAIParser )
	
	//----------------------------------------------------------------//
					MOAIParser				();
					~MOAIParser				();
	void			RegisterLuaClass		( MOAILuaState& state );
	void			RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
