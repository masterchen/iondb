/******************************************************************************/
/**
@file		iinq_user.h
@author		Dana Klamut
@brief		This code contains definitions for iinq user functions
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

#if !defined(IINQ_EXECUTE_H_)
#define IINQ_EXECUTE_H_

#if defined(__cplusplus)
extern "C" {
#endif

#include "../../dictionary/dictionary_types.h"
#include "../../dictionary/dictionary.h"
#include "../iinq.h"

/**
@brief		The table created through a CREATE TABLE statement.
@see		iinq_table
*/
typedef struct iinq_table ion_table_t;

/**
@brief		A supertype for the table created through a CREATE TABLE statement.
*/
struct iinq_table {
	char				*table_name;/**> Name of database table. */
	ion_key_type_t		key_type;	/**> Key type of specified primary key. */
	ion_key_size_t		key_size;	/**> Key size of specified primary key. */
	ion_value_size_t	value_size;	/**> Size of all attributes in table. */
};

/**
@brief		An attribute to be stored in an ion_table_t.
@see		iinq_attribute
*/
typedef struct iinq_attribute ion_attribute_t;

/**
@brief		A supertype for iinq attributes.
*/
struct iinq_attribute {
	char			*field_name;/**> Name of field. */
	ion_key_type_t	field_type;	/**> Data type of field. */
};

void
SQL_execute(
	ion_table_t *table,
	char		*sql
);

#if defined(__cplusplus)
}
#endif

#endif