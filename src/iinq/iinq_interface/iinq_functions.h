/******************************************************************************/
/**
@file		iinq_functions.h
@author		Dana Klamut
@brief		This code contains definitions for iinq pre-defined functions
@copyright	Copyright 2017
			The University of British Columbia,
			IonDB Project Contributors (see AUTHORS.md)
@par Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
@par 1.Redistributions of source code must retain the above copyright notice,
	this list of conditions and the following disclaimer.
@par 2.Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.
@par 3.Neither the name of the copyright holder nor the names of its contributors
	may be used to endorse or promote products derived from this software without
	specific prior written permission.
@par THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
	ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
	LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
	SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
	INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
	CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
	POSSIBILITY OF SUCH DAMAGE.
*/
/******************************************************************************/

#include "../../key_value/kv_system.h"
#include "../../util/sort/sort.h"
#include "../iinq.h"
#include "iinq_user_functions.h"

#if !defined(IINQ_FUNCTIONS_H_)
#define IINQ_FUNCTIONS_H_

#if defined(__cplusplus)
extern "C" {
#endif

/**
@brief		Struct defining all IINQ SQL statement methods.
@see		prepared_iinq
*/
typedef struct prepared_iinq iinq_prepared_sql;

/**
@brief		A dictionary_handler is responsible for dealing with the specific
			interface for an underlying dictionary, but is decoupled from a
			specific implementation.
*/
struct prepared_iinq {
	void (*execute)(
		iinq_prepared_sql	/* Prepared SQL statement object */
	);
	/**< A pointer to the prepared statement's execute function. */
	void (*setParam)(
		iinq_prepared_sql,	/* Prepared SQL statement object */
		int,/* Position of variable to be set in prepared statement */
		void *	/* Value to set variable to */
	);

	/**< A pointer to the prepared statement's setString function. */
	unsigned char	*value;	/* Value parsed from the prepared statement */
	unsigned char	*key;	/* Key to be inserted */
	unsigned char	*table;	/* The table name, stored as a unique identifier */
};

void
insert(
	char			*table_name,
	void			*key,
	unsigned char	*value
);

/**
@brief		This is the available value types for IINQ.
*/
typedef enum IINQ_VALUE_TYPE {
	/**> Field value is an int value. */
	value_type_int,
	/**> Field value is a char array value. */
	value_type_char,
	/**> Field value is a varchar value. */
	value_type_varchar,
	/**> Field value is a float value. */
	value_type_float
} iinq_value_type_t;

#if defined(__cplusplus)
}
#endif

#endif /* IINQ_FUNCTIONS_H */