static const unsigned int lt_hash = 31;

static const char *__errors[] = 
{
  [ERR_NONE] = "No errors",

#ifndef BUFF_H
  /*Buffer*/
  [ERR_BUFF_ALLOC_FAILURE] = "Buffer allocation failure",
  [ERR_BUFF_REALLOC_FAILURE] = "Buffer reallocation failure",
  [ERR_BUFF_OUT_OF_SPACE] = "Fixed buffer is out of space.",
#endif
#ifndef PARSELY_H 
#endif
#ifndef TAB_H 
	[ERR_LT_ALLOCATE]         = "Failed to allocate space for Table",
	[ERR_LT_OUT_OF_SPACE]     = "Out of space",
	[ERR_LT_INVALID_VALUE]    = "Attempted to add invalid value.",
	[ERR_LT_INVALID_TYPE]     = "Invalid type requested.",
	[ERR_LT_INVALID_INDEX]    = "Attempted to access uninitialized index.",
	[ERR_LT_OUT_OF_SLICE]     = "Value is out of requested range",	
	[ERR_LT_INDEX_MAX]        = "No errors",	
#endif

#ifndef RENDER_H 
#endif
 
#ifndef SQROOGE_H 
  [ERR_DB_OPEN]         = "Failed to open database." ,
  [ERR_DB_CLOSE]        = "Failed to close database." ,
  [ERR_DB_PREPARE_STMT] = "Failed to prepare database statement." ,
  [ERR_DB_BIND_VALUE]   = "Failed to bind value." ,
  [ERR_DB_STEP]         = "Failed to execute statement." ,
  [ERR_DB_BIND_LONG]    = "Error binding SQL %s at position %d: %s." ,
#endif

#ifndef RAND_H 
#endif

#ifndef TIMER_H 
	[ERR_LITE_TIMER_ERROR]        = "Timer error occurred!\n" ,
#endif
#ifndef OPT_H 
	[ERR_LITE_OPT_EXPECTED_ANY]   = "Expected argument after flag %s\n" ,
	[ERR_LITE_OPT_EXPECTED_STRING]= "Expected string after flag %s\n" ,
	[ERR_LITE_OPT_EXPECTED_NUMBER]= "Expected number after flag %s\n" ,
#endif
#ifndef SOCKET_H 
#endif
#ifndef SINW_H
	[ERR_POLL_INITIAL_ALLOCATOR]        = "File allocation failure.\n",
	[ERR_POLL_TOO_MANY_FILES]           = "Attempt to open too many files.\n",
	[ERR_POLL_RECVD_SIGNAL ]            = "Received signal interrupting accept().\n",
	[ERR_SPAWN_ACCEPT]                  = "Accept failure.\n",
	[ERR_SPAWN_NON_BLOCK_SET]           = "Could not make child socket non-blocking.\n",
	[ERR_SPAWN_MAX_CLIENTS]             = "Server has reached maximum number of clients.\n",
	[ERR_READ_CONN_RESET]               = "Connection reset by peer.\n",
	[ERR_READ_EGAIN]                    = "No data received, please try reading again.\n",
	[ERR_READ_EBADF]                    = "No file to receive data from. " \
                                        "Peer probably closed connection.\n",
	[ERR_READ_EFAULT]                   = "Server out of space for reading messages.\n",
	[ERR_READ_EINVAL]                   = "Read of socket is impossible due to " \
                                        "misalignment or use of O_DIRECT.\n",
	[ERR_READ_EINTR]                    = "Fatal signal encountered.\n",
	[ERR_READ_EISDIR]                   = "File descriptor supplied belongs to directory.\n",
	[ERR_READ_CONN_CLOSED_BY_PEER]      = "Connection closed by peer\n",
	[ERR_READ_BELOW_THRESHOLD]          = "Data read was below minimum threshold.\n",
	[ERR_READ_MAX_READ_RETRY_REACHED]   = "Maximum read retry limit reached for " 
                                        "this client\n",
	[ERR_WRITE_CONN_RESET]              = "Connection was reset before writing packet " \
                                        "could resume.\n",
	[ERR_WRITE_EGAIN]                   = "No data written, please try writing again.\n",
	[ERR_OUT_OF_MEMORY]                 = "Out of memory.\n",
	[ERR_REQUEST_TOO_LARGE]             = "The request made was too large.\n",
	[ERR_WRITE_EBADF]                   = "No file to write data to. " \
                                        "Peer probably closed connection.\n",
	[ERR_WRITE_EFAULT]                  = "Attempt to write message too large for buffer.\n",
	[ERR_WRITE_EFBIG]                   = "Attempt to write message too large for buffer.\n",
	[ERR_WRITE_EDQUOT]                  = "File quota of server has been reached.\n",
	[ERR_WRITE_EINVAL]                  = "ERR_WRITE_EINVAL...\n",
	[ERR_WRITE_EIO]                     = "ERR_WRITE_EIO...\n",
	[ERR_WRITE_ENOSPC]                  = "Kernel buffer exhausted.\n",
	[ERR_WRITE_EINTR]                   = "Fatal signal encountered.\n",
	[ERR_WRITE_EPIPE]                   = "Fatal signal encountered.\n",
	[ERR_WRITE_EPERM]                   = "Fatal: Permission denied when attempting to " \
                                        "write to socket.\n",
	[ERR_WRITE_EDESTADDREQ]             = "...\n", /*UDP error*/
	[ERR_WRITE_CONN_CLOSED_BY_PEER]     = "WRITE_CONN_CLOSED_BY_PEER...\n",
	[ERR_WRITE_BELOW_THRESHOLD]         = "Data write was below minimum threshold.\n",
	[ERR_WRITE_MAX_WRITE_RETRY_REACHED] = "Maximum write retry limit reached " \
                                        "for this client\n", 
#endif
	[ERR_ERR_INDEX_MAX]        = "No errors",
};


#ifndef UTIL_H
//lf_         - an iterator for reading files sequentially
//lf_start    - get "metadata" (size, chunks, etc)
//lf_continue - read another portion and return it
//lf_close    - close the stream

//Extract a hostname from a hostname string


//Return a hash code with a block of memory
static int lt_hashu (unsigned char *ustr, int len, int size)
{
	unsigned int hash=lt_hash;
	for (int i=0; i<len; i++) hash += ((hash*31) + hash) + ustr[i];
	return hash % size;
}


int hashint( char *str )
{
	return lt_hashu( (uint8_t *)str, strlen( str ), 8 );
}



//Write a string or blob as hex
const char *hash_long ( char *dest, const unsigned char *src, int len, int dlen )
{
	memset( dest, 0, dlen );
	for ( int i=0, p=0; i < len; i++, src++, p += 2 ) {
		fprintf( stderr, "%c -> %02x\n", *src, *src );
		snprintf( (char *)&dest[ p ], 3, "%02x", *src );
	}

	fprintf( stderr, "strlen(final): %ld\n", strlen( dest ));
	return (char *)dest;
}

const char *shash_long ( const char *src, int len )
{
	char aa[ 3 ] = { 0 };
	char *f = NULL;
	int s = 0;
	Buffer b;
	bf_init( &b, NULL, 1 );

	for ( int i=0, p=0; i < len; i++, src++, p += 2 ) 
	{
		//fprintf( stderr, "%c -> %02x\n", *src, *src );
		snprintf( aa, 3, "%02x", *src );
		bf_append( &b, (uint8_t *)aa, strlen( aa ));
	}

	bf_append( &b, (uint8_t *)"\0", 1 );
	s = bf_written( &b );
	f = malloc( s );
	memset( f, 0, s );
	memcpy( f, bf_data(&b), s ); 
	write( 2, bf_data( &b ), bf_written( &b ) );	
	bf_free( &b );
	return f;
}




//Combine a string using varargs and buff
const char *str_combine ( Buffer *b, const char *delim, ... )
{
	int a = 1;
	char *p = NULL;
	va_list args;
	va_start( args, delim );
	bf_init( b, NULL, 1 );

	while ((p = va_arg( args, char *)) ) 
	{
		bf_append( b, (unsigned char *)p, strlen( p ));
		bf_append( b, (unsigned char *)delim, strlen( delim ));
	} 

	va_end( args );
	p = (char *)bf_data( b );
	p[ bf_written( b ) - strlen(delim) ] = '\0';
	return ( char * )bf_data( b );
}


//Combine a string using varargs and buff

char *strcmbm ( const char *delim, ... )
{
	int a = 1, s = 0;
	char *ret=NULL, *p = NULL;
	va_list args;
	va_start( args, delim );
	Buffer b;
	memset( &b, 0, sizeof( Buffer ));
	bf_init( &b, NULL, 1 );

	while ((p = va_arg( args, char *)) ) 
	{
		bf_append( &b, (unsigned char *)p, strlen( p ));
		( delim ) ? bf_append( &b, (unsigned char *)delim, strlen( delim )) : 0;
	} 

	va_end( args );
	s = bf_written( &b ); 
	p = (char *)bf_data( &b );
	p[ s - strlen(delim) ] = '\0';
	ret = malloc( s );
	memset( ret, 0, s );
	memcpy( ret, p, strlen( p ) );	
	bf_free( &b );	
	return ret;
}


//Here is a quick and shitty file load function
//Notice how only error codes are returned...
int load_file2 (uint8_t *dest, const char *file, int *size)
{
	struct stat sb;
	memset( &sb, 0, sizeof(struct stat) );
	int fd = 0, rd = 0;
	
	//Open the static file you're looking for (404 if it can't be found)
	if ( stat(file, &sb) == -1 || (fd = open(file, O_RDONLY)) == -1 )
		return ERR_FILE_NOT_FOUND;

	//Read the file into allocated space 
	if ((rd = read(fd, dest, sb.st_size)) == -1)
		return ERR_FILE_READ_ERROR;

	//read can be handled differently here...
	
	//Close seperately
	if ( close(fd) == -1 )
		return ERR_FILE_CLOSE;

	*size = sb.st_size;
	return 1;
}





//Here is a far better file load function which utilizes buffers
//I need an iterator function, especially for chunked-encoding
int load_file (Buffer *dest, const char *file, int *size)
{
	struct stat sb;
	memset( &sb, 0, sizeof(struct stat) );
	int len, fd = 0, rd = 0, od = 0, td = 0;
	uint8_t buff[ READLENGTH ] = { 0 };
	
	//Open the static file you're looking for (404 if it can't be found)
	if ( stat(file, &sb) == -1 || (fd = open(file, O_RDONLY)) == -1 )
		return ERR_FILE_NOT_FOUND;
	
	od = sb.st_size;

	//Unfortunately, I need to copy into userspace before copying to mem
	while ( od )
	{
		//Read the file into allocated space 
		if ((rd = read( fd, buff, READLENGTH )) == -1)
			return ERR_FILE_READ_ERROR;
		
		//Add to it via buffer
		if ( !bf_append( dest, buff, rd ) )
			return ERR_BUFF_OUT_OF_SPACE;

		od -= rd;
	}

	//Close seperately
	if ( close(fd) == -1 )
		return ERR_FILE_CLOSE;

	//We assume that if we got here, sb.st_size was read...
	*size = sb.st_size;
	return 1;
}
#endif


//Trim any characters 
unsigned char *trim (uint8_t *msg, char *trim, int len, int *nlen) 
{
	//Define stuff
	uint8_t *m = msg;
	int nl= len;
	//Move forwards and backwards to find whitespace...
	while ( memchr(trim, *(m + ( nl - 1 )), 4) && nl-- ) ; 
	while ( memchr(trim, *m, 4) && nl-- ) m++;
	*nlen = nl;
	return m;
}

#ifndef OPT_H
//Set values when the user asks for them
static _Bool opt_set_value (char **av, Value *v, char type, char *err) 
{
	/*Get original flag and other things.*/
	char flag[64]={0}; 
	snprintf(flag, 63, "%s", *av);
	av++;

	/*Catch what may be a flag*/
	if (!*av || (strlen(*av) > 1 && *av[0] == '-' && *av[1] == '-'))
		return (snprintf(err, 1023, "Expected argument after flag %s\n", flag) && 0); 
	
	/*Evaluate the three different types*/
	if (type == 'c') {
		v->c = *av[0];	
	}
	else if (type == 's') {
		_Bool isstr=0;
		for (int i=0;i<strlen(*av); i++) { 
			/*We can safely assume this is an ascii string, if this passes*/
			if ((*av[i] > 32 && *av[i] < 48) || (*av[i] > 57 && *av[i] < 127)) {
				isstr = 1;
				break;
			}
		}

		if (!isstr)
			return (snprintf(err, 1023, "Expected string after flag %s\n", flag) && 0);
		v->s = *av;	
	}
	else if (type == 'n') {
		char *a = *av; /*Crashes for some reason if I just use dereference*/
		for (int i=0;i<strlen(a); i++)
			if ((int)a[i] < 48 || (int)a[i] > 57) /*Not a number check*/
				return (snprintf(err, 1023, "Expected number after flag %s\n", flag) && 0);
		v->n = atoi(*av);	
	}

	return 1; 
}


//Dump all options and show a usage message.
_Bool opt_usage (Option *opts, const char *prog, const char *msg, int status) 
{
	if (prog && msg)
		fprintf(stderr, "%s: %s\n", prog, msg);
	else if (msg)
		fprintf(stderr, "%s\n", msg);
	while (!opts->sentinel) { 
		if (opts->type != 'n' && opts->type != 'c' && opts->type != 's') 
			fprintf(stderr, "%-2s, %-20s %s\n", opts->sht ? opts->sht : " " , opts->lng, opts->description);
		else {
			char argn[1024]; memset(&argn, 0, 1024);
			snprintf(argn, 1023, "%s <arg>", opts->lng);
			fprintf(stderr, "%-2s, %-20s %s\n", opts->sht ? opts->sht : " " , argn, opts->description);
		}
		opts++;
	}
	exit(status);
	return 1;
}


//Check if an option was set by a user
_Bool opt_set (Option *opts, const char *flag) 
{
	Option *o = opts;
	while (!o->sentinel) {
		if (strcmp(o->lng, flag) == 0 && o->set)
			return 1; 
		o++;
	}
	return 0;
}


//Return a value if it was set, or a nil value (NULL for strings, 0 for numbers)
Value opt_get (Option *opts, const char *flag) 
{
	Option *o = opts;
	while (!o->sentinel) {
		if (strcmp(o->lng, flag) == 0)
			return o->v; 
		o++;
	}
	return o->v; /*Should be the last value, and it should be blank*/
}



//Evaluate options that the user gave and die with a message
_Bool opt_eval (Option *opts, int argc, char **av) {
	/*Evaulate options*/
	char buf[1024]={0};
	while (*av) {
		Option *o=opts;
		while (!o->sentinel) {
			//Find option, set boolean, and run a validator callback
			if ((o->sht && strcmp(*av, o->sht) == 0) || (o->lng && strcmp(*av, o->lng) == 0)) {
				o->set=1;
				if (o->callback) {
					if (!o->callback(++av, &o->v, buf))
						return 0;
				}
				else if (o->type == 'n' || o->type == 's' || o->type == 'c') {
					if (!opt_set_value(av, &o->v, o->type, buf)) {
						//errprintf(buf);
						return 0;
					}
				}
			}
			o++;
		}
		av++;
	}
	return 1;
}
#endif

#ifndef BUFF_H
//Initialize a buffer
Buffer *bf_init (Buffer *b, uint8_t *mem, int size) 
{
	memset( b, 0, sizeof (Buffer) );
	if ( mem )
	{
		b->fixed = 1;
		b->size  = size;	
		b->buffer = mem; 
		b->written = 0;
	}
	else {
		b->written = 0;
		b->size = 0;
		b->fixed = 0;
		if ( !(b->buffer = malloc( size )) )
			return NULL;
	}

	return b;
}


//This will help "clean" things
void bf_softinit (Buffer *b)
{
	memset( b, 0, sizeof (Buffer) );
	b->buffer = NULL;
}


//Set the written size if a buffer has data already
void bf_setwsize (Buffer *b, int size) 
{
	b->size = size;
}



//Write data to buffer
int bf_append (Buffer *b, uint8_t *s, int size) 
{
	if ( !b->fixed ) {
		if ((size + b->written) > b->size) 
		{
			uint8_t *c = NULL;
			if ( !(c = realloc( b->buffer, size + b->size )) )
			{
				b->error = ERR_BUFF_REALLOC_FAILURE;
				return 0;
			}
			b->size    = size + b->size;
			b->buffer  = c;		
		}
	}
	else {
		if ((size + b->written) > b->size) 
		{
			b->error = ERR_BUFF_OUT_OF_SPACE;
			return 0;	
		}	
	}

	memcpy( &b->buffer[ b->written ], s, size );
	b->written += size;
	return 1;
}



//Move data in a buffer
int bf_prepend (Buffer *b, uint8_t *s, int size)
{
	//If it's malloc'd, allocate the new space and move the memory
	if ( !b->fixed ) {
		uint8_t *c = NULL;
		if ( !(c = realloc( b->buffer, size + b->size )) )
		{
			b->error = ERR_BUFF_REALLOC_FAILURE;
			return 0;
		}
		b->size    = size + b->size;
		b->buffer  = c;		
		memmove( &b->buffer[size], &b->buffer[0], b->written );
		memcpy( &b->buffer[ 0 ], s, size );
		b->written += size;
	}

	//If it's not, check that the buffer has enough and then move
	return 1;
}


//Get currently written amount
int bf_written (Buffer *b) {
	return (b) ? b->written : 0;
}



//Get the unsigned char data
uint8_t *bf_data (Buffer *b) {
	return (b) ? b->buffer : 0;
}


//Write out errors
const char *bf_err (Buffer *b) {
	return __errors[b->error];
}



//Destroy a buffer's data
void bf_free (Buffer *b) 
{
	if (( b->buffer ) && (!b->fixed)) 
	{
		free( b->buffer ); 
		b->buffer  = NULL;
		b->size    = 0;
		b->written = 0;
		b->error   = 0;
		b->fixed   = 0;
	}
}

#endif



#ifndef PARSELY_H
void pr_prepare( Parser *p )
{
#if 0
	//
	if (len > INT_MAX) {
		return NULL;
	}
#endif

	//Clear found character table and set hash table to all -1	
	memset(p->founds, 0, sizeof(p->founds));
			
	//Extract first character and use it as a truth index
	for (int i=0; i<32; i++) {
		struct words *w = &p->words[i];
		if ( !w->word ) 
			return;
		p->founds[ (int)w->word[0] ] = 1;
	}
}


//We might want the match, or readahead (this can be specified by the character)
Parser *pr_next( Parser *p, unsigned char *src, int len ) 
{
	//p->prev is always 0 at first
	p->prev  = p->next;
	p->match = (unsigned char *)p->matchbuf;

	//Set current pointer to current position
	p->word  = &src[p->prev];

	//Zero length ought to be rejected
	if ( len == 0 )  
		return NULL;

	//loop through the entire block
	while ( p->next < len ) 
	{
		/*Stop skipping if this is a match*/
		if ( (p->marker & PARSER_MATCH_CATCH) && *p->word == *p->words[p->find].catch ) 
		{
			int nl = len - p->next;
			int wl = 0;
			char *m = p->words[p->find].catch;

		#if 0
			//Check if it's supposed to be negated
			if ( p->words[p->find].negate ) {
			} 
			if ( (p->marker & PARSER_NEGATE_MATCH) ) {
			} 
		#endif
			
			//Check that this is indeed a match
			if ( (nl > (wl = strlen(m))) && memcmp(p->word, m, wl) == 0 ) {
				//p->prev += 1/*why the extra 1?*/;
				memset(p->match, 0, PARSER_MAXMATCH_LEN);
				memcpy(p->match, &src[p->prev], p->tokenSize);
				p->prev += p->tokenSize/*why the extra 1?*/;
				p->size = (p->next /*+= p->tokenSize*/ /*+ wl*/) - p->prev;
				p->next += p->tokenSize;
				p->marker = 0x00;
				return p;	
			}
		}

		/*Found a single character from rng*/
		if ( !p->marker && p->founds[ (int)*p->word ] )  
		{
			int nl = len - p->next;
			int wl = 0;
			p->find = -1;

			//Check that this is a real token match 
			for (int i=0; i<32; i++) {
				struct words *w = &p->words[i];
				if ( !w->word )
					break;
				//If there's a match, mark things accordingly
				if ( (nl > (wl = strlen(w->word))) && memcmp( p->word, w->word, wl ) == 0 ) {
					p->find = i;
					p->tokenSize = wl;
					break;
				}
			}

			//write the matching token here
			if ( p->find == -1 ) 
				p->tokenSize = 0;
			//check if it's a "bit" token
			else if ( p->words[p->find].catch )
				p->marker |= PARSER_MATCH_CATCH;
			//or just handle it
			else {
				//Copy token to match pointer
				memset(p->match, 0, PARSER_MAXMATCH_LEN);
				memcpy(p->match, p->word, p->tokenSize);
				p->match[p->tokenSize + 1] = '\0';

				//set the block size
				p->size  = (p->next /*+= p->tokenSize*/) - p->prev;
				p->next += p->tokenSize;
				return p;
			}
		}

		//move up through both characters
		p->word++, p->next++;
	}

#if 0
	//Length of 1 should be returned, but no longer
	if ( len == 1 )
		return NULL;
#endif

	//The last match should be returned
	if ( !p->end ) 
	{
		if ( p->next == len ) 
		{
			p->word = NULL;
			p->end  = 1;
			p->size = len - p->prev;
			return p;
		}
	}

	return NULL;
}


//print a parser structure
void pr_print ( Parser *p ) 
{
	fprintf ( stderr, "p->marker   %d\n", p->marker );
	fprintf ( stderr, "p->size     %d\n", p->size   );
	fprintf ( stderr, "p->prev     %d\n", p->prev   );
	fprintf ( stderr, "p->next     %d\n", p->next   );
}
#endif


#ifndef MIME_H
static const Mime mime[] = {
/*sed -n 7,115p mime.c | sed 's/\t//' | awk -F ' ' '{ printf "  { %13s %-80s },\n", $2, $3 }'*/ 
  {    "unknown", "application/octet-stream"                                      /*octet-stream*/ },
  {       "html", "text/html"                                             /*default content-type*/ },
  {        "htm", "text/html"                                                                      },
  {         "7z", "application/x-7z-compressed"                                                    },
  {        "aac", "application/x-aac"                                                              },
  {        "abc", "text/vnd.abc"                                                                   },
  {        "apk", "application/vnd.android.package-archive.xul+xml"                                },
  {          "a", "text/vnd.a"                                                                     },
  {       "atom", "application/atom+xml"                                                           },
  {        "avi", "video/avi"                                                                      },
  {        "caf", "application/x-caf"                                                              },
  {        "cmd", "text/cmd"                                                                       },
  {        "css", "text/css"                                                                       },
  {        "csv", "text/csv"                                                                       },
  {       "dart", "application/vnd.dart"                                                           },
  {        "deb", "application/vnd.debian.binary-package"                                          },
  {       "djvu", "image/vnd.djvu"                                                                 },
  {        "doc", "application/vnd.ms-word"                                                        },
  {       "docx", "application/vnd.openxmlformats-officedocument.wordprocessingml.document"        },
  {        "dtd", "application/xml-dtd"                                                            },
  {        "dvi", "application/x-dvi"                                                              },
  {       "ecma", "application/ecmascript"                                                         },
  {        "eml", "message/partial"                                                                },
  {        "eml", "message/rfc822"                                                                 },
  {       "flac", "audio/flac"                                                                     },
  {        "flv", "video/x-flv"                                                                    },
  {        "gif", "image/gif"                                                                      },
  {         "gz", "application/gzip"                                                               },
  {       "http", "message/http"                                                                   },
  {        "ico", "image/vnd.microsoft.icon"                                                       },
  {       "iges", "model/iges"                                                                     },
  {       "imdn", "message/imdn+xml"                                                               },
  { "javascript", "text/javascript"                                                                },
  {       "jpeg", "image/jpeg"                                                                     },
  {        "jpg", "image/jpeg"                                                                     },
  {         "js", "application/javascript"                                                         },
  {       "json", "application/json"                                                               },
  {         "js", "text/javascript"                                                                },
  {        "kml", "application/vnd.google-earth.kml+xml"                                           },
  {        "kmz", "application/vnd.google-earth.kmz+xml"                                           },
  {        "l24", "audio/l24"                                                                      },
  {       "m3u8", "application/x-mpegURL"                                                          },
  {         "md", "application/x-markdown"                                                         },
  {       "mesh", "model/mesh"                                                                     },
  {        "mht", "message/rfc822"                                                                 },
  {      "mhtml", "message/rfc822"                                                                 },
  {       "mime", "message/rfc822"                                                                 },
  {       "mk3d", "video/x-matroska"                                                               },
  {        "mka", "video/x-matroska"                                                               },
  {        "mks", "video/x-matroska"                                                               },
  {        "mkv", "video/x-matroska"                                                               },
  {        "mp3", "audio/mp3"                                                                      },
  {        "mp4", "audio/mp4"                                                                      },
  {        "mp4", "video/mp4"                                                                      },
  {       "mpeg", "audio/mp3"                                                                      },
  {        "msh", "model/mesh"                                                                     },
  {       "nacl", "application/x-nacl"                                                             },
  {        "odg", "application/vnd.oasis.opendocument.graphics"                                    },
  {        "odp", "application/vnd.oasis.opendocument.presentation"                                },
  {        "ods", "application/vnd.oasis.opendocument.spreadsheet"                                 },
  {        "odt", "application/vnd.oasis.opendocument.text"                                        },
  {        "ogg", "audio/ogg"                                                                      },
  {        "ogt", "video/ogg"                                                                      },
  {       "opus", "audio/opus"                                                                     },
  {        "pdf", "application/pdf"                                                                },
  {       "pkcs", "application/x-pkcs12"                                                           },
  {      "pnacl", "application/x-pnacl"                                                            },
  {        "png", "image/png"                                                                      },
  {        "ppt", "application/vnd.ms-powerpoint"                                                  },
  {       "pptx", "application/vnd.openxmlformats-officedocument.presentationml.presentation"      },
  {         "ps", "application/postscript"                                                         },
  {  "quicktime", "video/quicktime"                                                                },
  {         "ra", "audio/vnd.rn-realaudio"                                                         },
  {        "rar", "application/x-rar-compressed"                                                   },
  {        "rdf", "application/rdf+xml"                                                            },
  {        "rss", "application/rss+xml"                                                            },
  {        "rtf", "text/rtf"                                                                       },
  {        "sit", "application/x-stuffit"                                                          },
  {       "smil", "application/smil+xml"                                                           },
  {       "soap", "application/soap+xml"                                                           },
  {        "svg", "image/svg+xml"                                                                  },
  {        "swf", "application/x-shockwave-flash"                                                  },
  {        "tar", "application/x-tar"                                                              },
  {        "tex", "application/x-latex"                                                            },
  {       "tiff", "image/tiff"                                                                     },
  {        "tif", "image/tiff"                                                                     },
  {        "ttf", "application/x-font-ttf"                                                         },
  {        "txt", "text/plain"                                                                     },
  {       "ulaw", "audio/basic"                                                                    },
  {      "vcard", "text/vcard"                                                                     },
  {     "vorbis", "audio/vorbis"                                                                   },
  {       "vrml", "model/vrml"                                                                     },
  {        "wav", "audio/vnd.wave"                                                                 },
  {       "webm", "audio/webm"                                                                     },
  {        "wmv", "video/x-ms-wmv"                                                                 },
  {       "woff", "application/font-woff"                                                          },
  {       "woff", "application/x-font-woff"                                                        },
  {        "wrl", "model/vrml"                                                                     },
  {          "x", "application/EDIFACT"                                                            },
  {          "x", "application/EDI-X12"                                                            },
  {        "xcf", "application/x-xcf"                                                              },
  {      "xhtml", "application/xhtml+xml"                                                          },
  {        "xls", "application/vnd.ms-excel"                                                       },
  {       "xlsx", "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"              },
  {        "xml", "application/xml"                                                                },
  {        "xml", "text/xml"                                                                       },
  {        "xop", "application/xop+xml"                                                            },
  {        "xps", "application/vnd.ms-xpsdocument"                                                 },
  {        "xul", "application/vnd.mozilla.xul+xml"                                                },
  {        "zip", "application/zip"                                                                },
};


/*Get extension and find the filetype*/
const char *mtref (const char *mimename) {
	int s = strlen(mimename);
	for (int c = 0; c < (sizeof(mime)/sizeof(Mime)); c++) 
	{
		if ( strcmp(mime[c].mimetype, mimename) == 0 ) {
			return mime[c].mimetype;
		}
	}

	//Default mimetype
	return mime[0].mimetype;
}

const char *file_type_from_mime (const char *filename) {
	return NULL;
}

/*Get extension and find the filetype*/
const char *mime_type_from_file (const char *filename) {
	int i=0, j=0;
	//Move back and find the extension, it should'nt be longer than 10 characters
	for (i=strlen(filename), j=0; i >= 0 || j < 10; i--, j++)
		if (filename[i] == '.') break;	

	//If there is no extension, we'll say it's text/html
	if (j == 0)
		return (char *)mime[0].mimetype;

	//hi	
	for (int c = 0; c<(sizeof(mime)/sizeof(Mime)); c++) {
		if (memcmp(mime[c].filetype, &filename[i + 1], j - 1) == 0)
			return (char *)mime[c].mimetype;
	}

	//Default mimetype
	return (char *)mime[0].mimetype;
}
#endif

#ifndef RENDER_H
static const char *endBlock = "}}";
static const char *trimchars = " \t\r\n^{}#!/";
 #ifdef RENDER_VERBOSE
void print_uint8t (uint8_t *src, int len, const char *msg)
{
	( msg ) ? fprintf( stderr, "%s: ", msg ) : 0;
	write( 2, "'", 1 );
	write( 2, src, len );
	write( 2, "'", 1 );
	write( 2, "\n", 1 );
}


int print_uerr (const char *err)
{
	fprintf( stderr, "render: " );
	fprintf( stderr, "%s\n", err );
	return 1;
}


#if 1
void print_body ( Bod *b )
{
	 niprintf( b->beg );
	 niprintf( b->end );
	 niprintf( b->start );
	 niprintf( b->finish );
	 niprintf( b->tableIndex );
	 niprintf( b->adjust );
	 niprintf( b->save );
	 niprintf( b->loop );
	 niprintf( b->loopKeyLen );
	 niprintf( b->loopValueLen );
 #if 0
	char    *srcTable;
	uint8_t *tok,
	        *loopKey,
					*loopValue,
					*value,
					*loopBuf;
 #endif
}
#endif
#endif


static void render_dump_mark ( Render *r )
{
	Mark *ct = &r->markers[0];
	while ( ct->blob )
	{
		fprintf( stderr, "{ size:   %-4d,", ct->size  );
		fprintf( stderr,  " type:   %-1d,", ct->type  );
		fprintf( stderr,  " index:  %-4d,", ct->index );
		fprintf( stderr,  " action: %-6s,'",
			&"RAW  \0""-LOOP\0""^LOOP\0""$LOOP\0""STUB \0""DIRECT"[ ct->action * 6 ] ); 
		for ( int i=0 ; i < ct->size ; i++ )
			fprintf( stderr, "%c", (ct->blob[ i ] == '\n' ) ? '@' : ct->blob[ i ] ); 
		//write( 2, ct->blob, ct->size );
		fprintf( stderr, "' },\n" );
		ct++;
	}
}


//render_init - Initializes a render block
int render_init ( Render *r, Table *t )
{
	r->depth = 0;
	r->maxbuf = 2048;
	r->srctable = t;
	memset( r->buf, 0, RENDER_MAX_BUF_SIZE );
	return ( !bf_init( &r->dest, NULL, 1 ) ) ? 0 : 1;
}



//Set the render
void render_free ( Render *r )
{
	free( r->markers );
	bf_free( &r->dest );
}



//Set the render source data?
void render_set_srcdata (Render *r, uint8_t *src)
{
	r->src = src;
}



//Set the render source
void render_set_srctable (Render *r, Table *t)
{
	r->srctable = t;
} 


//Do a map
int render_map ( Render *r, uint8_t *src, int srclen )
{
	//Define stuff
	Parser p   = {.words = {{"{{#"}, {"{{/"}, {"{{^"}, {"{{>"}, {"{{"}, {"}}"}, {NULL}}};
	Mark *raw  = NULL, 
			  *ct  = NULL; 
	int follow = 1;
	pr_prepare( &p );

	//Prepare the markers
	if ( !(r->markers = malloc( sizeof( Mark ) )) )
		return 0;
	else 
	{
		memset( r->markers, 0, sizeof(Mark) );
		ct = r->markers;
	}

	//Loop through a thing
	for ( int alloc=2, t;  pr_next( &p, src, srclen );  ) 
	{
		//Copy the last of the stream
		if ( p.word == NULL )
		{
			ct->action = RAW;
			ct->blob = &src[ p.prev ];
			ct->size = srclen - p.prev; 
			REALLOC( raw, r->markers );
			break;
		}

		//Just mark each section (and it's position)
		if ((t = p.word[ p.tokenSize - 1 ]) == '#')
		{
			ct->blob = &src[p.prev],
			ct->size = p.size,
			ct->action = RAW;
			REALLOC( raw, r->markers );
			ct->action = POSLOOP;
		}
		else if (t == '^') {
			ct->blob = &src[p.prev],
			ct->size = p.size,
			ct->action = RAW;
			REALLOC( raw, r->markers );
			ct->action = NEGLOOP;
		}
		else if (t == '/') {
			ct->blob = &src[p.prev],
			ct->size = p.size,
			ct->action = RAW;
			REALLOC( raw, r->markers );
			ct->action = ENDLOOP;
		}
		else if (t == '{')
		{
			ct->blob = &src[p.prev],
			ct->size = p.size,
			ct->action = RAW;
			REALLOC( raw, r->markers );
			ct->action = DIRECT;
		}
		else if (t == '}' /*|| t == '!'*/ )
		{
			//Anything within here will always be a table
			ct->blob  = trim( (uint8_t *)&src[ p.prev ], (char *)trimchars, p.size, &ct->size );

			if ( *ct->blob == '.' )
				ct->action = STUB;
			else {
				ct->index = lt_get_long_i( r->srctable, ct->blob, ct->size );
				ct->type  = lt_vta( r->srctable, ct->index );
				if ((ct->type == LITE_TBL) && (ct->action == POSLOOP || ct->action == NEGLOOP))
					ct->parent = ct->blob, ct->psize = ct->size;	
			}
			REALLOC( raw, r->markers );
		}
	}

	//render_dump_mark( r );
	return 1;
}



//Append to block
static int append ( uint8_t *dest, int dmax, uint8_t *src, int srclen, int item, int *pos )
{
	if ( *pos + srclen >= dmax ) 
		return -1;
	else 
	{
		if ( item == -1 )
		{
			memcpy( &dest[ *pos ], src, srclen );
			*pos += srclen;
		}
		else 
		{
			char buf[ 64 ] = { 0 };
			int sl = snprintf( buf, 64, "%d", item );
			memcpy( &dest[ *pos ], buf, sl );
			*pos += sl;
		}
	}
	return *pos;
}



//Render
int render_render ( Render *r )
{
	//Loops can just use pointers... probably...
	Mark *lt=NULL, *ct = &r->markers[0];
	unsigned char search[ 2048 ];
	struct DT { Mark *mark; uint8_t *src, *parent; int size, psize, skip, times, position; } d[10]; 

	//everytime you descend, src is what you got, size is length of src
	//and times is times to repeat
	struct DT *dt = d;
	memset( search, 0, sizeof(search) );
	memset( dt, 0, sizeof (struct DT));
	
	while ( ct->blob ) 
	{
		//Is the skip bit on?
		if ( ct->action != ENDLOOP && dt->skip ) 
			{ ct++; continue; }
		else if ( ct->action == ENDLOOP ) 
		{
			//Stop skipping if these match
			if ( ct->size == dt->psize && (memcmp( dt->parent, ct->blob, dt->size ) == 0))
			{
				if ( dt->skip )
					dt->skip = 0;
				else {
#if 0
					//Write
					write( 2, dt->parent, dt->psize );
					fprintf( stderr, " => " );
					write( 2, ct->blob, ct->size );
#endif
					//Decrement repetition
					if ( dt->times == 0 )
						dt--;
					else {
						--dt->times;
						ct = dt->mark;
						continue;
					}
				}
			}
		}

		//Simply copy this data
		if ( ct->action == RAW )
			bf_append( &r->dest, ct->blob, ct->size );

		//Retrieve the reference and write it
		else if ( ct->action == DIRECT && ct->index > -1 )
		{
			//fprintf( stderr, "Direct reference is of type: %s", lt_typename( ct->type ));
			if ( ct->type == LITE_BLB )
				bf_append( &r->dest, lt_blobdata_at( r->srctable, ct->index ), lt_blobsize_at( r->srctable, ct->index ));
			else if ( ct->type == LITE_TXT ) {
				char *a = lt_text_at( r->srctable, ct->index );
				bf_append( &r->dest, (uint8_t *)a, strlen( a ) );
			}
			else if ( ct->type == LITE_INT )
			{ char a[ 64 ]={0}; 
				snprintf( a, 63, "%d", lt_int_at( r->srctable, ct->index )); 
				bf_append( &r->dest, (uint8_t *)a, strlen( a ) ); }
			else if ( ct->type == LITE_FLT )
			{ char a[ 128 ]={0}; 
				snprintf( a, 127, "%f", lt_float_at( r->srctable, ct->index )); 
				bf_append( &r->dest, (uint8_t *)a, strlen( a ) ); }
			else if ( ct->type == LITE_USR )
			{ char a[ 128 ]={0}; 
				snprintf( a, 127, "%p", lt_userdata_at( r->srctable, ct->index )); 
				bf_append( &r->dest, (uint8_t *)a, strlen( a ) ); }
			else if ( ct->type == LITE_TBL )
			{ char a[ 128 ]={0}; 
				snprintf( a, 127, "%p", (void *)&lt_table_at( r->srctable, ct->index )); 
				bf_append( &r->dest, (uint8_t *)a, strlen( a ) ); }
			else { 
				;//Skip all other types 
			}	
		}
		else if ( ct->action == STUB )
		{
			//Check if the key is .key or .value. This will allow me to loop through keys and values...
			int i=0, p=0;
			memcpy( &search[ p ], dt->parent, dt->psize );
			p += dt->psize;
			p += snprintf( (char *)&search[ p ], 64, ".%d", dt->times );
			memcpy( &search[ p ], ct->blob, ct->size );
			p += ct->size;
		
#if 1
			write( 2, search, p );
			write( 2, "\n", 1 );
			//getchar();
#endif
		
			if ( (i = lt_get_long_i( r->srctable, search, p )) == -1 )
				{ ct++; continue; }//fprintf( stderr, "Looks like there's nothing here..." );		
			else 
			{
				uint8_t *src = NULL;
				LiteType t = lt_vta( r->srctable, i );
				memset( search, 0, sizeof(search) );

				if (t == LITE_USR)
					p = snprintf( (char *)( src = search ), sizeof(search), "%p", lt_userdata_at( r->srctable, i ));
				else if (t == LITE_FLT) 
					p = snprintf( (char *)( src = search ), sizeof(search), "%0.2f", lt_float_at( r->srctable, i ));
				else if (t == LITE_INT)
					p = snprintf( (char *)( src = search ), sizeof(search), "%d", lt_int_at( r->srctable, i ));
				else if (t == LITE_TBL)
					p = snprintf( (char *)( src = search ), sizeof(search), "%p", &lt_table_at( r->srctable, i ));
				else if (t == LITE_TXT)
					p = strlen( lt_text_at(r->srctable, i) ), src = (uint8_t *)lt_text_at( r->srctable, i );
				else if (t == LITE_BLB) 
					p = lt_blobsize_at( r->srctable, i), src = lt_blobdata_at( r->srctable, i ); 
				else {
					ct++;
					continue;
				}
				bf_append( &r->dest, src, p ); 
			}	
			memset( search, 0, sizeof(search) );
		}
		else if ( ct->action == NEGLOOP || ct->action == POSLOOP )
		{
			if ( ct->action == NEGLOOP && ct->index > -1 )
				dt->skip = 1; //Set something
			else 
			{
				if ( ct->index == -1 )
					dt->skip = 1;
				else 
				{
					//No looping necessary
					if ( ct->type != LITE_TBL )
						;
					else 
					{
						dt++;
						memset( dt, 0, sizeof (struct DT));
						//Skip completely if this is a table and there are no entries
						if ( (dt->times = lt_counti( r->srctable, ct->index )) > 0 )
						{
							--dt->times;  /*Adjust count b/c the sentinel has its own index*/
							//dt->times -= 2;  /*Adjust count b/c the sentinel has its own index*/
							dt->mark = ct + 1;
							dt->psize = ct->size;
							dt->parent = ct->blob;
						}
					}
				}
			}
		}

		ct++;
	}
	
	return 1;
}


//Return what was rendered
Buffer *render_rendered (Render *r) 
{
	return &r->dest;
}
#endif

#ifndef TAB_H
 #ifdef LT_MAX_HASH
  static const int lt_max_slots     = LT_MAX_HASH;
 #else
  static const int lt_max_slots     = 7;
 #endif
 #ifdef DEBUG_H
  static const char *fmt = "%-4s\t%-10s\t%-5s\t%-10s\t%-30s\t%-6s\t%-20s\n";
 #endif
static const LiteRecord nul = { 0 };
static const LiteRecord *supernul = &nul;
static const int lt_maxbuf        = 64;
static const int lt_buflen        = 4096;
static const char *lt_polymorph_type_names[] = 
{
	[LITE_NON] = "uninitialized", 
	[LITE_INT] = "integer",     
	[LITE_FLT] = "float",     
	[LITE_TXT] = "text",     
	[LITE_BLB] = "blob",     
#ifdef LITE_NUL
	[LITE_NUL] = "null",     
#endif
	[LITE_USR] = "userdata",     
	[LITE_TBL] = "table",     
	[LITE_TRM] = "terminator",     
	[LITE_NOD] = "node",     
};


//Build a string or some other index in reverse
static int build_backwards (LiteKv *t, unsigned char *buf, int bs)
{ 
	//This should return if there is no value...
	int    size =  0,  
           mm = bs;
	LiteKv   *p =  t; 

	while (p)
	{
		//This should only run if there is a blob or pKey	
		if (p->key.type == LITE_INT || p->key.type == LITE_FLT) 
		{
			char b[128] = {0};
			double f = (t->key.type == LITE_FLT) ? p->key.v.vfloat : (double)p->key.v.vint;
			int a =	snprintf( b, 127, (t->key.type == LITE_FLT) ? "%f" : "%.0f", f);
			mm -= strlen(b);
			memcpy( &buf[ mm ], b, a );
			buf[ --mm ] = '.';
		}
		else if (p->key.type == LITE_BLB) {
			LiteBlob *b = &p->key.v.vblob;
			mm -= b->size;
			memcpy( &buf[ mm ], b->blob, b->size );
			buf[ --mm ] = '.';
		}
		else if (p->key.type == LITE_TXT) {
			char *b = p->key.v.vchar;
			mm -= strlen(b);
			memcpy( &buf[ mm ], b, strlen(b));
			buf[ --mm ] = '.';
		}
		else {
			return -1;
		}
		p = p->parent;
	}

	//Copy and clean
	size = bs - (++mm);
	memmove( &buf[ 0 ], &buf[ mm ], size );
	memset( &buf[size], 0, bs - size );
	buf[size] = '\0';
	return size;
}



#ifdef DEBUG_H 
#endif

//Trim things
unsigned char *lt_trim (uint8_t *msg, char *trim, int len, int *nlen) 
{
	//Define stuff
	uint8_t *m = msg;
	int nl= len;
	//Move forwards and backwards to find whitespace...
	while ( memchr(trim, *(m + ( nl - 1 )), 4) && nl-- ) ; 
	while ( memchr(trim, *m, 4) && nl-- ) m++;
	*nlen = nl;
	return m;
}



//Count indicies in a table. If index is greater than 1 and the item is a "table", then will return the number of elements in said table
int lt_counti ( Table *t, int index )
{
	//Return count of all elements
	if ( index == -1 )
		return t->count;
	else if ( index == 0 )
	{
		if ( lt_vta( t, index ) != LITE_TBL )
			return t->count;
		else 
		{
			LiteTable *tt = &lt_table_at( t, index );
			return ( tt ) ? (tt->count - 1) : 0;
		}
	}
	else 
	{
		//Return one for elements that exist, but aren't tables
		if ( lt_vta( t, index ) != LITE_TBL )
			return 1;
		else 
		{
			LiteTable *tt = &lt_table_at( t, index );
			return ( tt ) ? (tt->count - 1) : 0;
		}
	}
	return 0;
}











//Clear error
void lt_clearerror (Table *t) 
{
	t->error = 0;
}


//Return errors as strings
const char *lt_strerror (Table *t)
{
	//Paranoid bounds checking
	return ( t->error > -1 && t->error < ERR_LT_INDEX_MAX) ? __errors[ t->error ] : NULL; 
}

//Initiailizes a table data structure
Table *lt_init (Table *t, LiteKv *k, int size) 
{
	//Calculate optimal modulus for hashing
	if ( size <= 63 )
		t->modulo = 63; 
	else if ( size <= 127 )
		t->modulo = 127; 
	else if ( size <= 511 )
		t->modulo = 511; 
	else if ( size <= 1027 )
		t->modulo = 1027;
	else if ( size <= 2047 )
		t->modulo = 2047; 
	else if ( size <= 4091 )
		t->modulo = 4091; 
	else if ( size <= 8191 )
		t->modulo = 8191; 
	else if ( size <= 16383)
		t->modulo = 16383; 
	else if ( size <= 32767)
		t->modulo = 32767; 
	else if ( size <= 65535)
		t->modulo = 65535; 
	else if ( size <= 65535)
		t->modulo = 131067; 
	else if ( size <= 131067)
		t->modulo = 199999; 
	else if ( size <= 199961 )
		t->modulo = 199999; 
	else
		t->modulo = 511997; 

	int actual_size = size;
	t->mallocd = (!k) ? 1 : 0;

	//Allocate space for users that don't pass in their own structure 
	if ( !k )
	{
		actual_size = t->modulo;
		k = malloc(t->modulo * sizeof(LiteKv));
		if ( !k ) 
		{	
			t->error = ERR_LT_ALLOCATE;
			return 0;
		}
	}

	if ( memset((void *)k, 0, sizeof(LiteKv) * actual_size) == NULL ) 
	{
		t->error = ERR_LT_ALLOCATE;
		return 0;
	}

	//Initialize all hash entries to -1
	for (int i=0; i < actual_size; i++)
		memset( k[i].hash, -1, sizeof(int) * lt_max_slots );

	//Set this
	t->current = NULL;
	t->src     = NULL;
	t->srcmallocd = 0;
	t->error   = 0;
	t->cptr    = -1;
	t->total   = actual_size;
	t->count   = 0;
	t->head    = k;
	t->index   = 0;
	t->start   = 0;
	t->end     = 0;
	t->rCount  = &t->count;
	//t->parent = NULL;

	//Lastly, increment tte pointer by one so we can always follow it
	return t;
}



//Adds a value to a table data structure
LiteType lt_add ( Table *t, int side, LiteType lt, int vi, float vf,
	char *vc, unsigned char *vb, unsigned int vblen, void *vn, Table *vt, char *trim )
{

	if ( t->index >= t->total ) 
	{
		t->error = ERR_LT_OUT_OF_SPACE;
		return 0;
	}
		
	LiteValue  *v = (!side) ? &(t->head + t->index)->key : &(t->head + t->index)->value;
	LiteRecord *r = &v->v;
	v->type       = lt;

	//Check for zero length blobs or text
	if ( ( lt == LITE_BLB || lt == LITE_TXT ) && !vblen )
		return 0;

	//Set each value to its matching type
	if ( lt == LITE_INT )
	{
		r->vint = vi;
	#ifdef DEBUG_H
		SHOWDATA( "Adding int %s %d to table at %p", ( !side ) ? "key" : "value", r->vint, ( void * )t );
	#endif
	}
	else if ( lt == LITE_FLT )
	{
		r->vfloat = vf;
	#ifdef DEBUG_H
		SHOWDATA( "Adding float %s %f to table at %p", ( !side ) ? "key" : "value", r->vfloat, ( void * )t );
	#endif
	}
#ifdef LITE_NUL
	else if ( lt == LITE_NUL )
	{
		r->vnull = NULL;
	#ifdef DEBUG_H
		SHOWDATA( "Adding null %s to table at %p", ( !side ) ? "key" : "value", ( void * )t );
	#endif
	}
#endif
	else if ( lt == LITE_USR )
	{
		r->vusrdata = vn;
	#ifdef DEBUG_H
		SHOWDATA( "Adding userdata %p to table at %p", ( void * )r->vusrdata, ( void * )t );
	#endif
	}
	else if ( lt == LITE_TBL )
	{
	#ifdef DEBUG_H
		SHOWDATA( "Adding invalid value table!" );
	#endif
		return ( t->error = ERR_LT_INVALID_VALUE ) ? -1 : -1;
	}
	else if ( lt == LITE_BLB )
	{
		r->vblob.blob = vb, r->vblob.size = vblen;
	#ifdef DEBUG_H
		SHOWDATA( "Adding blob %s of length %d to table at %p", (!side) ? "key" : "value", r->vblob.size, ( void * )t );
	#endif
	}
	else if ( lt == LITE_TXT )
	{
		//Even though this says LITE_TXT, the assumption 
		//is that tab needs to duplicate the data. 
		r->vchar = malloc( vblen + 1 );
		if ( !r->vchar )
			return 0;
		else 
		{
			memset( r->vchar, 0, vblen + 1 );
			memcpy( r->vchar, vb, vblen );
			r->vchar[ vblen ] = '\0';
		#ifdef DEBUG_H
			SHOWDATA( "Adding text %s '%s' to table at %p", ( !side ) ? "key" : "value", r->vchar, ( void * )t );
		#endif
		}
	}
	else 
	{
	#ifdef DEBUG_H
		SHOWDATA( "Attempted to add unknown %s type to table at %p", ( !side ) ? "key" : "value", ( void * )t );
	#endif
		return 0;
	}
	return lt;
}



//Return types
LiteType lt_rettype( Table *t, int side, int index )
{
	if ( index < 0 || index > t->count )
		return ( t->error = ERR_LT_INVALID_INDEX ) ? 0 : 0;
	return (!side) ? (t->head + index)->key.type : (t->head + index)->value.type; 
}



//Return typenames
const char *lt_rettypename( Table *t, int side, int index )
{
	if ( index < 0 || index > t->count ) 
	{
		t->error = ERR_LT_INVALID_INDEX; 
		return lt_polymorph_type_names[ 0 ];
	}
	LiteType i = (!side) ? (t->head + index)->key.type : (t->head + index)->value.type;
	return lt_polymorph_type_names[ (int) i ];
}


const char *lt_typename (int type)
{
	return ( type > -1 && type <= LITE_NOD ) ? lt_polymorph_type_names[ type ] : NULL;
}



//Descend one level (creating a table)
int lt_move (Table *t, int dir) 
{
	//Out of space
	if ( t->index > t->total ) 
	{
		t->error = ERR_LT_OUT_OF_SPACE;
		return -1;
	}

	//LiteValue *curr  = &(t->head + t->index)->value;
	LiteKv *curr     = (t->head + t->index);
	LiteKv **cptr    = &curr;
	LiteValue *value = &curr->value;


	//Left or right?	
	if ( !dir )
	{
	#ifdef DEBUG_H
		SHOWDATA( "Descending into table value to table at %p", ( void * )t );
	#endif
		//Set count of elements in this new table to actual count
		LiteTable *T = &value->v.vtable;
		value->type  = LITE_TBL;
		t->rCount    = &T->count;

		/*Yay*/
		T->parent  = ( !t->current ) ? NULL : t->current;
		T->ptr     = *(long *)&T; 
		//T->ptr   = (int)T; //for some reason, GCC doesn't like this...
		t->current = T;
	}
	else 
	{
		//Set references
		LiteValue *key = &curr->key; 
		key->type      = LITE_TRM;
		value->type    = LITE_NUL;
		LiteRecord *r  = &key->v;	
	#ifdef DEBUG_H
		SHOWDATA( "Ascending from inner table within at %p", ( void * )t );
	#endif

		//
		if ( !t->current->parent )
		{
			t->rCount = &t->count;
			r->vptr = (long)t->current->ptr;
		}
		else if ( t->current->parent )
		{
			r->vptr = (long)t->current->ptr;
			LiteTable *T = t->current->parent;
			t->rCount = &T->count;
			t->current = T;
		}
	}
		
	lt_finalize (t);
	return 1;
}



//Finalize adding to both sides of a table data structure
void lt_finalize (Table *t)
{
	( *t->rCount )++;
	t->count ++;
	t->index ++;
}



//Hash each key
void lt_lock (Table *t)
{
	//Might not be able to reuse this...	
	LiteKv *parent = NULL;
	LiteValue *v   = NULL;

	for (int i=0; i <= t->index; i++) 
	{
		//Get reference
		LiteKv   *tt = t->head + i,
					 *slot = NULL;
		int       pp = 0,
               h = 0;

		//Make a new buffer
		unsigned char buf[ LT_POLYMORPH_BUFLEN ];
		memset( buf, 0, LT_POLYMORPH_BUFLEN );

		//Check keys and values...
		if (tt->value.type == LITE_NUL )
		{
			v = NULL;
			if (parent)
				parent = parent->parent;
			continue;
		}

		//Set parent of an item.
		if ( parent )	
			tt->parent = parent, v = &tt->value;
	
		//Do parents here
		if (tt->value.type == LITE_TBL)
			parent = tt;

		//Build a string to hash, save the hash somewhere 
		pp   = build_backwards( tt, buf, LT_POLYMORPH_BUFLEN );
		h    = lt_hashu( buf, pp, t->modulo );
		slot = t->head + h;

		//Find an available slot
		for ( int m=0, j=0; !j && m < lt_max_slots; m++ )
		{
			slot->hash[m] == -1 ?	slot->hash[ m ] = i, j=1 : 0;
		}
	}
}




//Return index in table where key was found
int lt_get_long_i (Table *t, unsigned char *find, int len) 
{
	LiteKv *hv   = NULL;
	int     hash = 0,  
          hh   = 0;
	uint8_t *f   = NULL;
	uint8_t gb[ LT_POLYMORPH_BUFLEN ] = { 0 };

	if ( len > LT_POLYMORPH_BUFLEN )
		return -1;

	if ( len < 0 )
		return -1;

	if ( !t->start && !t->end ) 
		hash = lt_hashu( f = find, len, t->modulo );
	else 
	{
		//Ewww..
		int a = 0;
		memcpy( &gb[0], t->buf, t->buflen );
		if ( *find != '.' )
		{
			a = 1;
			memcpy( &gb[ t->buflen ], ".", 1 ); 
		}	
		memcpy( &gb[ t->buflen + a ], find, len );
		hash = lt_hashu( gb, t->buflen + a + len, t->modulo );
		f = gb;
	}

	//Find the key
	for ( int i=0 ; !hv && i < 5; i++ ) 
	{
		uint8_t buf[LT_POLYMORPH_BUFLEN] = {0};
		//fprintf( stderr, "%d, %d, %d\n", hh, hash, i );

		if ((hh = (t->head + hash)->hash[i]) == -1 || i == lt_max_slots )
		{
#if 0
			fprintf( stderr, "#1 error\n" );
#endif
			return -1;
		}

#if 0
		fprintf( stderr, "hash %d, hh %d, current pos in slot arr: %d\n", hash, hh, i );
#endif

		if ( !(hv = t->head + hh) )
		{
#if 0
			fprintf( stderr, "#2 error\n" );
#endif
			return -1;
		}
	
		//?	
		if (build_backwards( hv, buf, LT_POLYMORPH_BUFLEN ) == -1)
		{
#if 0
			fprintf( stderr, "#3 error\n" );
#endif
			return -1;
		}

#if 0
		fprintf( stderr, "looking for: '%s' (len: %d) => found: '%s' (len: %d)\n", 
			buf, (int)strlen((char *)buf), find, len );
#endif

		hv = ( memcmp(f, buf, len) == 0) ? hv : 0;
	}

	//Pull the value if it's in the acceptable range
	if ( !t->start && !t->end )
		return hh;
	else 
	{
		//fprintf( stderr, "nums[3] => %d, %d, %d", t->start, hh, t->end );
		return ( hh > t->start && hh < t->end ) ? hh : -1;	
	}

}



//Return LiteKv at certain index
LiteValue *lt_retany (Table *t, int index)
{
	return ( index <= -1 || index > t->count ) ? NULL : &(t->head + index)->value; 
}


int lt_exists (Table *t, int index)
{
	return ( index <= -1 || index > t->count );
}



//Return a LiteRecord matching a certain type at a certain index
LiteRecord *lt_ret (Table *t, LiteType type, int index)
{
		if ( index <= -1 || index > t->count ) 
		{
			t->error = ERR_LT_INVALID_INDEX;
			return (LiteRecord *)supernul; 
		}
#if 0
	}
	else 
	{
		if ( index <= -1 || index < t->start || index > t->end )
		{
			t->error = ERR_LT_OUT_OF_SLICE;
			return (LiteRecord *)supernul;
		}	
	}
#endif	

	if ( (t->head + index)->value.type != type ) 
		return (LiteRecord *)supernul; 

	return &(t->head + index)->value.v; 
}



//Set the current index to another one
int lt_set (Table *t, int index)
{
	return ( index <= -1 || index > t->count ) ? -1 : (t->index = index);
}



//Reset a table index
void lt_reset (Table *t)
{
	t->start = 0;
	t->end   = 0;
	t->index = 0;
}



//Iterate through the indices of a table
LiteKv *lt_next (Table *t)
{
	LiteKv *curr = (t->index > t->count) ? NULL : t->head + t->index;
	t->index++;
	return curr;
}



//Loop from another point...
LiteKv *lt_items_by_index (Table *t, int ind)
{
	//Find a hash, and if it's a table... set some stuff
	LiteKv *curr = NULL;

	if ( t->cptr == -1 )
	{
		if ( (t->head + ind)->value.type != LITE_TBL ) 
			return NULL;
		t->index = ind;
		t->cptr = (t->head + ind)->value.v.vtable.ptr;
	}

	//
	if (t->index > t->count) 
		return NULL;

	//Set reference
	curr = t->head + t->index;

	//Check the key name and see if it matches t->cptr, return null if so
	if ( curr->key.type == LITE_TRM && curr->key.v.vptr == t->cptr ) 
	{
		t->index = 0;
		t->cptr = -1;
		return NULL;
	}

	//Increment and move on
	t->index++;
	return curr;
}



//Find a table by hash and return until it has no more keys.
LiteKv *lt_items_i (Table *t, uint8_t *src, int len)
{
	//Find a hash, and if it's a table... set some stuff
	LiteKv *curr = NULL;

	//Check for a hash table
	if ( t->cptr == -1 )
	{
		int in;
		if ( (in = lt_get_long_i ( t, src, len )) == -1 )
			return NULL;

		if ( (t->head + in)->value.type != LITE_TBL ) 
			return NULL;
		
		t->index = in;
		t->cptr = (t->head + in)->value.v.vtable.ptr;
	}

	//
	if (t->index > t->count) 
		return NULL;

	//Set reference
	curr = t->head + t->index;

	//Check the key name and see if it matches t->cptr, return null if so
	if ( curr->key.type == LITE_TRM && curr->key.v.vptr == t->cptr ) 
	{
		t->index = 0;
		t->cptr = -1;
		return NULL;
	}

	//Increment and move on
	t->index++;
	return curr;
} 



//Set a data source
void lt_setsrc (Table *t, void *src)
{
	t->src = src;
}


//Will set boundaries on a new table
Table *lt_within_long( Table *st, uint8_t *src, int len )
{
#if 0
	//You can allocate the string here if both start and from are null
	if ( !t->start && !t->end )
	{
		if ( !(t->buf =  malloc( len + 2048 )) )
			return NULL;
		else {
			memcpy( t->buf, src, len );
		}
	}
#endif

	//Whenever we look for a string, we copy til the end
	int a      = 0;
	int count  = 0;
	st->buf    = src;  //set the buffer
	st->buflen = len;

	//Search for a table	
	if ( (a = lt_get_long_i( st, src, len )) == -1 || lt_vta( st, a ) != LITE_TBL )
		return NULL;

	//Set start and end, then return the table
	st->start = a;
	st->end   = a + (&lt_table_at( st, a ))->count;
	return st;
}


void lt_unset (Table *t)
{
	if (t->buf) 
	{
		free( t->buf );
		t->buf = NULL;
	}
}

//Copy from start index to end index
//A macro will handle copying tables (and it'd be even better to do it without duplication)
Table *lt_copy (Table *dest, Table *src, int from, int to)
{
	//Get a count of all elements
	int index = 0;
	int start = (from < 0 ) ? 0 : from;
	int end   = (to == -1) ? src->index : to;
#if 0
	Table *tt = NULL;
	//Have to allocate a new table here
	if ( !(tt = malloc( sizeof(Table))) )
	{
		t->error = ERR_LT_ALLOCATE;
		return NULL;
	}
#endif

#if 0
	//Create one on heap (expensive...)
	if ( !(dest = lt_init( dest, NULL, lt_counti( t, index ))) )
	{	
		t->error = ERR_LT_ALLOCATE;
		return NULL;
	}
	//Loop through each requested element and add it
	for (int ii=start; ii <= end; ii++) 
	{
		LiteValue *r[3] = 
		{
			&(t->head + ii)->key,
			&(t->head + ii)->value,
			NULL,	
		};
#define lt_mega( ... )
		for ( LiteValue **v=r; *v; v++ )
		{
			LiteValue *vv = *v;
			/*LITE_NODE is handled in printall*/
			if (vv->type == LITE_NON)
				lt_mega( tt );
			else if (vv->type == LITE_NUL)
				lt_mega( tt );
			else if (vv->type == LITE_USR)
				lt_mega( tt );
			else if (vv->type == LITE_TBL) 
				lt_mega( tt );
			else if (vv->type == LITE_FLT || vv->type == LITE_INT)
				lt_mega( tt );
			else if (vv->type == LITE_FLT)
				lt_mega( tt );
			else if (vv->type == LITE_TXT)
				lt_mega( tt );
			else if (vv->type == LITE_TRM)
				lt_mega( tt );
			else if (vv->type == LITE_BLB) 
				lt_mega( tt );
		}
	}
	//Lock so hashing works	
	lt_lock( tt );
#endif
	return NULL;
}


//Get a key or value somewhere
void lt_free (Table *t) 
{	
	//Free any text keys
	for ( int ii=0; ii < t->index; ii++ )
	{
		LiteKv *k = t->head + ii;
		( k->key.type == LITE_TXT ) ? free( k->key.v.vchar ), k->key.v.vchar = NULL : 0;
		( k->value.type == LITE_TXT ) ? free( k->value.v.vchar ), k->value.v.vchar = NULL : 0;
	}

	if ( t->mallocd )
	{
		free( t->head );
		t->head   = NULL;	
		t->error  = 0;
		t->total  = 0;
		t->count  = 0;
		t->index  = 0;
		t->rCount = NULL;
		t->mallocd= 0;
	}

	if ( t->srcmallocd /*t->src*/ )
	{
		free( t->src );
		t->src = NULL;
	}
}

//Print out an initialized table
void lt_printt (Table *t) 
{
	fprintf( stderr, "t->total:      %d\n", t->total );
	fprintf( stderr, "t->modulo:     %d\n", t->modulo );
	fprintf( stderr, "t->index:      %d\n", t->index );
	fprintf( stderr, "t->count:      %d\n", t->count );
	fprintf( stderr, "t->rCount:     %p\n", (void *)t->rCount );
	fprintf( stderr, "t->head:       %p\n", (void *)t->head );
}


//Dump a table
void lt_dump (Table *t) 
{
	int level = 0;	
	int ct = t->index;

	//Loop through each index
	for (int i=0; i <= ct; i++) 
	{
		LiteType vt = (t->head + i)->value.type;
		fprintf ( stderr, "[%-5d] %s", i, &"\t\t\t\t\t\t\t\t\t\t"[ 10 - level ]);
		lt_printindex( t->head + i, level );
		level += ( vt == LITE_NUL ) ? -1 : (vt == LITE_TBL) ? 1 : 0;
	}
}


//Print a set of values at a particular index
static void lt_printindex (LiteKv *tt, int ind)
{
	int         w = 0;
  char b[lt_buflen]; 
	memset(b, 0, lt_buflen);
	struct { int t; LiteRecord *r; } items[2] = {
		{ tt->key.type  , &tt->key.v    },
		{ tt->value.type, &tt->value.v  } 
	};

	for ( int i=0; i<2; i++ ) 
	{
		LiteRecord *r = items[i].r; 
		int t = items[i].t;
		if ( i ) 
		{
			memcpy( &b[w], " -> ", 4 );
			w += 4;
			/*LITE_NODE is handled in printall*/
			if (t == LITE_NON)
				w += snprintf( &b[w], lt_buflen - w, "%s", "is uninitialized" );
#ifdef LITE_NUL
			else if (t == LITE_NUL)
				w += snprintf( &b[w], lt_buflen - w, "is terminator" );
#endif
			else if (t == LITE_USR)
				w += snprintf( &b[w], lt_buflen - w, "userdata [address: %p]", r->vusrdata );
			else if (t == LITE_TBL) 
			{
				LiteTable *rt = &r->vtable;
				w += snprintf( &b[w], lt_buflen - w, 
					"table [address: %p, ptr: %ld, elements: %d]", (void *)rt, rt->ptr, rt->count );
			}
		}
		if (t == LITE_FLT || t == LITE_INT)
			w += snprintf( &b[w], lt_buflen - w, "%d", r->vint );
		else if (t == LITE_FLT)
			w += snprintf( &b[w], lt_buflen - w, "%f", r->vfloat );
		else if (t == LITE_TXT)
			w += snprintf( &b[w], lt_buflen - w, "%s", r->vchar );
		else if (t == LITE_TRM)
			w += snprintf( &b[w], lt_buflen - w, "%ld", r->vptr );
		else if (t == LITE_BLB) 
		{
			LiteBlob *bb = &r->vblob;
			if ( bb->size < 0 )
				return;	
			if ( bb->size > lt_maxbuf )
				w += snprintf( &b[w], lt_buflen - w, "is blob (%d bytes)", bb->size);
			else {
				memcpy( &b[w], bb->blob, bb->size ); 
				w += bb->size;
			}
		}
	}

	write(2, b, w);
	write(2, "\n", 1);
}	



#ifdef DEBUG_H 
//Get a key or value somewhere
void lt_printall ( Table *t ) 
{
#ifdef DEBUG_H
	//Header
	fprintf( stderr, fmt, "Index", "KType", "VType", "Value", "CombinedValue", "HashOf", "Hashes" );
#endif

	for ( int ii=0; ii < t->index; ii++ )
	{
		LiteKv *k = t->head + ii;
		LiteType kt;
		int hash;	
		const char *kk=NULL, *vv=NULL;
		char bkbuf[1024] = {0}, 
         strbuf[512] = {0},
				 inbuf[11] = {0},
				 habuf[11] = {0},
         nmbuf[125] = {0};

		//Index
		sprintf(inbuf, "%d", ii);
		
		//Hashes
		for ( int i=0, j=0; i < lt_max_slots ; i++ )
			j += sprintf( &nmbuf[ j ], "%3d,",  k->hash[ i ] );

		//Key and value types
		kk = lt_rettypename( t, 0, ii );
		vv = lt_rettypename( t, 1, ii );

		//Finally, the key itself (the whole thing, I suppose)
		if ((kt = lt_rettype( t, 0, ii )) == LITE_INT )
			sprintf( strbuf, "%d, ", (t->head + ii )->key.v.vint );
		else if ( kt == LITE_TXT )
			sprintf( strbuf, "%s, ", (t->head + ii )->key.v.vchar );
		else if ( kt == LITE_BLB ) 
		{
			int size = (t->head + ii )->key.v.vblob.size;
			if ( size > 1024 ) 
				sprintf( strbuf, "%s, ", "Blob too large" );
			else {
				memcpy( strbuf, (t->head + ii )->key.v.vblob.blob, size );
				strbuf[ size ] = '\0';
			}
		}
	
		//Build a string backwards
		build_backwards( t->head + ii, (uint8_t *)bkbuf, 1024 );
		hash = lt_hashu( (uint8_t *)bkbuf, strlen(bkbuf), t->modulo );
		sprintf( habuf, "%d", ( kt == LITE_NON ) ? -1 : hash );
		fprintf( stderr, fmt, inbuf, kk, vv, strbuf, bkbuf, habuf, nmbuf );
	}
}
#endif
#endif

#ifndef MEM_H
/*Compare to uint8_t's*/
_Bool memstr (const void * a, const void *b, int size) 
{
	int32_t ct=0, len = strlen((const char *)b);
	const uint8_t *aa = (uint8_t *)a;
	const uint8_t *bb = (uint8_t *)b;
	_Bool stop=1;
	while (stop) {
		while ((stop = (ct < (size - len))) && memcmp(aa + ct, bb, 1) != 0) { 
			//fprintf(stderr, "%c", aa[ct]);
			ct++; continue; }
		if (memcmp(aa + ct, bb, len) == 0)
			return 1;	
		ct++;
	}
	return 0;	
}

//Return count of occurences of a character in some block.
int32_t memchrocc (const void *a, const char b, int32_t size) {
	_Bool stop=1;
	int32_t ct=0, occ=-1;
	uint8_t *aa = (uint8_t *)a;
	char bb[1] = { b };
	while (stop) {
		occ++;
		while ((stop = (ct < size)) && memcmp(aa + ct, bb, 1) != 0) ct++;
		ct++;
	}
	return occ;
}


//Return count of occurences of a string in some block.
int32_t memstrocc (const void *a, const void *b, int32_t size) {
	_Bool stop=1;
	int32_t ct=0, occ=0;
	uint8_t *aa = (uint8_t *)a;
	uint8_t *bb = (uint8_t *)b;
	int len     = strlen((char *)b);
	while (stop) {
		while ((stop = (ct < (size - len))) && memcmp(aa + ct, bb, 1) != 0) ct++;
		if (memcmp(aa + ct, bb, len) == 0) occ++;
		ct++;
	}
	return occ;
}



//Initialize a block of memory
_Bool memwalk (Mem *mm, uint8_t *data, uint8_t *tokens, int datalen, int toklen) {
#if 0
fprintf(stderr, "Inside memwalk: ");
write(2, data, datalen);
write(2, "\n", 1);
#endif
	int rc    = 0;
	mm->pos   = mm->next;
	mm->size  = memtok(&data[mm->pos], tokens, datalen - (mm->next - 1), toklen);
	if (mm->size == -1) {
	 mm->size = datalen - mm->next;
	}
	mm->next += mm->size + 1;
	//rc      = ((mm->size > -1) && (mm->pos <= datalen));
	rc        = (mm->size > -1);
	mm->chr   = !rc ? 0 : data[mm->next - 1];
	mm->pos  += mm->it;
	mm->size -= mm->it;
#if 0
fprintf(stderr, "rc: %d\n", rc);
fprintf(stderr, "datalen: %d\n", datalen);
fprintf(stderr, "mm->pos: %d\n", mm->pos);
fprintf(stderr, "mm->size: %d\n", mm->size);
#endif
	return rc; 
}


//Where exactly is a substr in memory
int32_t memstrat (const void *a, const void *b, int32_t size) 
{
	_Bool stop=1;
	int32_t ct=0;//, occ=0;
	uint8_t *aa = (uint8_t *)a;
	uint8_t *bb = (uint8_t *)b;
	int len     = strlen((char *)b);
	//while (stop = (ct < (size - len)) && memcmp(aa + ct, bb, len) != 0) ct++; 
	while (stop) 
	{
		while ((stop = (ct < (size - len))) && memcmp(aa + ct, bb, 1) != 0) ct++;
		if (memcmp(aa + ct, bb, len) == 0)
			return ct; 
		ct++;
	}
	return -1;
}


//Where exactly is a substr in memory
int32_t memchrat (const void *a, const char b, int32_t size) {
	_Bool stop=1;
	int32_t ct=0;// occ=0;
	uint8_t *aa = (uint8_t *)a;
	//uint8_t *bb = (uint8_t *)b;
	char bb[1] = { b };
	//while (stop = (ct < (size - len)) && memcmp(aa + ct, bb, len) != 0) ct++; 
	while ((stop = (ct < size)) && memcmp(aa + ct, bb, 1) != 0) ct++;
	return (ct == size) ? -1 : ct;
}


//Finds the 1st occurence of one char, Keep running until no tokens are found in range...
int32_t memtok (const void *a, const uint8_t *tokens, int32_t sz, int32_t tsz) 
{
	int32_t p=-1,n;
	
	for (int i=0; i<tsz; i++)
	#if 1
		p = ((p > (n = memchrat(a, tokens[i], sz)) && n > -1) || p == -1) ? n : p;
	#else
	{
		p = ((p > (n = memchrat(a, tokens[i], sz)) && n > -1) || p == -1) ? n : p;
		fprintf(stderr, "found char %d at %d\n", tokens[i], memchrat(a, tokens[i], sz));
		nmprintf("p is", p);
	}
	#endif
	
	return p;
}


//Finds the first occurrence of a complete token (usually a string). 
//keep running until no more tokens are found.
int32_t memmatch (const void *a, const char *tokens, int32_t sz, char delim) {
	int32_t p=-1, n, occ = -1;

	/*Check that the user has supplied a delimiter. (or fail in the future)*/
	if (!(occ = memchrocc(tokens, delim, strlen(tokens))))
		return -1 /*I found nothing, sorry*/;

	/*Initialize a temporary buffer for each copy*/
	int t = 0; 
	char buf[strlen(tokens) - occ];
	memset(&buf, 0, strlen(tokens) - occ);

	/*Loop through each string in the token list*/
	while (t < strlen(tokens) && (n = memtok(&tokens[t], (uint8_t *)"|\0", sz, 2)) > -1) {
		/*Copy to an empty buffer*/
		memcpy(buf, &tokens[t], n);
		buf[n] = '\0';
		t += n + 1;

		/*This should find the FIRST occurrence of what we're looking for within block*/
		p = ((p > (n = memstrat(a, buf, sz)) && n > -1) || p == -1) ? n : p;
		/*fprintf(stderr, "found str %s at %d\n", buf, memstrat(a, buf, sz)); nmprintf("p is", p);*/
		memset(&buf, 0, strlen(tokens) - occ);
	}
	return p;
}


/*Copy strings*/
char *memstrcpy (char *dest, const uint8_t *src, int32_t len) {
	memcpy(dest, src, len);
	dest[len]='\0';
	return dest;
}
#endif

#ifndef JSON_H
static uint8_t rootname[] = "root";
typedef struct { int text, type, key, index; } Depth; 


#if 0
//Trim any characters 
static unsigned char *json_trim (uint8_t *msg, char *trim, int len, int *nlen) 
{
	//Define stuff
	uint8_t *m = msg;
	int nl= len;
	//Move forwards and backwards to find whitespace...
	while ( memchr(trim, *(m + ( nl - 1 )), strlen(trim)) && nl-- ) ; 
	while ( memchr(trim, *m, strlen(trim)) && nl-- ) m++;
	*nlen = nl;
	return m;
}
#endif



#if 0
/*Slower, but cleaner*/
int json_reset ( Table *t, uint8_t **b, int *a, int side  )
{
	dump( *b, *a, "Adding value" );
	if ( side )
	{
		if ( lt_addbk( t, *b, *a ) ) 
		{
			fprintf( stderr, "%s\n", lt_strerror( t ));
			return 0;
		}
	}	
	else 
	{
		if ( lt_addbv( t, *b, *a ) ) 
		{
			fprintf( stderr, "%s\n", lt_strerror( t ));
			return 0;
		}
	}
	*b = NULL;
	*a = 0;
	return 1;
}
#endif



//Dump
#ifdef DEBUG_H
static void json_dump (uint8_t *a, int b, const char *msg)
{
	(msg) ? fprintf( stderr, "%s: ", msg ) : 0;
	write( 2, "'", 1 );
	write( 2, a, b );
	write( 2, "'\n", 2 );
}
#endif



//Get an approximation of the number of keys needed
int json_count ( uint8_t *src, int len )
{
	int sz = 0;
	int c = len;

	//You can somewhat gauge the size needed by looking for all commas
	for ( c=len; c; c-- )
		sz += ( memchr( "{[,]}", *src,  5 ) ) ? 1 : 0, src++;

	return sz;
}



//A very raw version that uses no special anything
int json_json ( Table *t, uint8_t *src, int len )
{
	//Define
	Depth depther[ JSON_MAX_DEPTH ];
	Depth *depth = &depther[0];
	int dwatch = 0;
	int sz = json_count( src, len ); 
	int adjust = 0;
	unsigned char *b = NULL;
	Parser p = { 
		.words = {
			{ (char *)"\"", "\"", "\\"  },
			{ "{" },
			{ "["   },
			{ "}" },
			{ "]"   },
			{ ":"  },
			{ ","  },
			{ NULL  }
		}
	};

	//Initialize the table structure (we are making some serious approximations)
	if ( !lt_init( t, NULL, sz ) )
		return err( 1, "Did not init lt...\n" );

	//Prepare everything
	memset( depther, 0, sizeof(Depth) * JSON_MAX_DEPTH );	
	pr_prepare( &p );	
	depth->type = 1;
	lt_addblobkey( t, rootname, 4 );

	//Some stats
	#if 0
	fprintf( stderr, "Read %d bytes from file '%s'\n", bytes, file );
	fprintf( stderr, "Requested size of %d for hash table\n", sz + 1000 );
	fprintf( stderr, "Initializing hash table with %d keys\n", t.modulo );
	#endif

	//make a JSON table out of this
	while ( pr_next( &p, src, len ) )
	{
		if (p.word == NULL)	
			break; 

		//Save reference to whatever string was found
		if ( *p.word == '"' )
		{
			b = trim( &src[ p.prev ], "\"' \t\n\r", p.size, &adjust );
			depth->text = 1;  
		}

		//Descend into a table.
		else if ( *p.word == '{' )
		{
			if ( !depth->type ) 
			{
				if ( lt_addintkey( t, depth->index++ ) == 0 )
				{
					//qprintf( "%s\n", lt_strerror( t ));
					return 0;
				}
			}

			qprintf( "Switching to alphabetical indices...\n" );
			lt_descend( t );
			( dwatch < 100 ) ? dwatch++, depth++ : 0;
			depth->type = 1;
		}

		//Descend into a table.
		else if ( *p.word == '[' ) 
		{
			qprintf( "Switching to numeric indices...\n" );
			lt_descend( t );	
			if ( lt_addintkey( t, depth->index++ ) == 0 )
			{
				//fprintf( stderr, "%s\n", lt_strerror( t ));
				return 0;
			}

			( dwatch < 100 ) ? dwatch++, depth++ : 0;
			depth->type = 0;
		}

		//There should always be a key in front of this
		else if ( *p.word == ':' )
		{	
			if ( depth->text )
			{
				dump( b, adjust, "Adding key" );
				lt_addbk( t, b, adjust );
				b = NULL;
				adjust = 0;
			}

			depth->text = 0;
			depth->key = 1;
		}

		//There is most likely a value before this
		else if ( *p.word == ',' )
		{
			//Add the key if there was text
			if ( depth->text ) 
			{
				dump( b, adjust, "Adding value" );
				lt_addbv( t, b, adjust );
				lt_finalize( t );
				b = NULL;
				adjust = 0;
				depth->text = 0;
			}

			depth->key = 0;
		}


		//Jump out (but we could be potentially be somewhere else)
		else if ( *p.word == '}' )
		{
			if ( depth->key )
			{
				//dump( b, a, "Adding value" );
				if ( depth->type ) 
				{
					lt_addbv( t, b, adjust );
					lt_finalize( t );	
					b = NULL;
					adjust = 0;
					depth->text = 0;
				}
			}

			lt_ascend( t );	
			memset( depth, 0, sizeof(Depth));	
			( dwatch > 0 ) ? dwatch--, depth-- : 0;
		}

		//Jump out (but we could be potentially be somewhere else)
		else if ( *p.word == ']' )
		{
			lt_ascend( t );
			memset( depth, 0, sizeof(Depth));	
			( dwatch > 0 ) ? dwatch--, depth-- : 0;
		}

		qprintf(  "match is:      %c\n", *p.word );
		dump( &src[ p.prev ], p.size, "Current value" );
		qprintf(  "level:         %d\n", dwatch);
		qprintf(  "keyType:       %s\n", !depth->type ? "numeric" : "alpha" );
	}

	lt_lock( t );
	return 1;
}



//...
void json_free ( Table *t )
{
	lt_free( t );
}



#endif


#ifndef SQROOGE_H 
static int boundarySize   = 9;
static const char  name[] = "sqwer";
static uint8_t boundary[] = 
 { '\0',  2,   3, 254,  3,   4, 253,  4,   5  ,  //next column
   '\0',  2, 255,   4,  3, 254,   5,  4, 253 }   //next row
;
//SQL boundary strings
static const char *sqlite3_C = "}}}}}}}}}";
static const char *sqlite3_N = "{{{{{{{{{";
static const char *sqlite3_E = "333333333";
static const int   sqlite3_L = 9;
static const SQWrite nullw[] = {{ .sentinel = 1 }};
static const SQWrite nullentry = { .sentinel = 1 };
//const SQWrite nullwriter = { .sentinel = 1 };
static const char *sqltypes[] = 
{
	[SQLITE_INTEGER] = "integer",
	[SQLITE_FLOAT]   = "float",
	[SQLITE_TEXT]    = "text",
	[SQLITE_BLOB]    = "blob",
	[SQLITE_NULL]    = "null",
	[SQ_DTE]         = "date",
};
static const char *sq_names[] = 
{
	"uninitialized",
	[SQ_INT] = "int",
	[SQ_FLT] = "float",
	[SQ_TXT] = "text",
	[SQ_BLB] = "blob",
	[SQ_NUL] = "null",
	[SQ_DTE] = "date",
};

//Forward declarations for the sake of keeping data organized
static _Bool sq_add_sqlite3_dateint (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool sq_add_sqlite3_int (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool sq_add_sqlite3_double (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool sq_add_sqlite3_text (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool sq_add_sqlite3_blob (sqlite3_stmt *stmt, int i, const SQWrite *w);

static _Bool pr_add_sqlite3_int (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool pr_add_sqlite3_double (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool pr_add_sqlite3_text (sqlite3_stmt *stmt, int i, const SQWrite *w);
static _Bool pr_add_sqlite3_blob (sqlite3_stmt *stmt, int i, const SQWrite *w);

static int sq_sqlite3_column_int (sqlite3_stmt *stmt, int col, uint8_t *);
static int sq_sqlite3_column_double (sqlite3_stmt *stmt, int col, uint8_t *);
static int sq_sqlite3_column_text (sqlite3_stmt *stmt, int col, uint8_t *);
static int sq_sqlite3_column_blob (sqlite3_stmt *stmt, int col, uint8_t *);

static int sz_sqlite3_column_any (sqlite3_stmt *stmt, int col, uint8_t *);

static int pr_sqlite3_column_int (sqlite3_stmt *stmt, int col, uint8_t *);
static int pr_sqlite3_column_double (sqlite3_stmt *stmt, int col, uint8_t *);
static int pr_sqlite3_column_text (sqlite3_stmt *stmt, int col, uint8_t *);
static int pr_sqlite3_column_blob (sqlite3_stmt *stmt, int col, uint8_t *);

static _Bool __sq_read_oneshot (const char *filename, const char *sql, int limit, SQWrite **ww);

/*Reader function pointers*/
static SQReader sq_readers[][7] = {
	{
		[SQLITE_INTEGER] = { .fp = sq_sqlite3_column_int },
		[SQLITE_FLOAT]   = { .fp = sq_sqlite3_column_double },
		[SQLITE_TEXT]    = { .fp = sq_sqlite3_column_text },
		[SQLITE_BLOB]    = { .fp = sq_sqlite3_column_blob },
		[SQLITE_NULL]    = { .fp = 0 },
	},
	{
		[SQLITE_INTEGER] = { .fp = pr_sqlite3_column_int },
		[SQLITE_FLOAT]   = { .fp = pr_sqlite3_column_double },
		[SQLITE_TEXT]    = { .fp = pr_sqlite3_column_text },
		[SQLITE_BLOB]    = { .fp = pr_sqlite3_column_blob },
		[SQLITE_NULL]    = { .fp = 0 },
	},
};

/*Insert function pointers*/
static SQInsert sq_inserters[][7] = {
	{ 
		[SQLITE_INTEGER] = { .fp = sq_add_sqlite3_int },
		[SQLITE_FLOAT]   = { .fp = sq_add_sqlite3_double },
		[SQLITE_TEXT]    = { .fp = sq_add_sqlite3_text },
		[SQLITE_BLOB]    = { .fp = sq_add_sqlite3_blob },
		[SQ_DTE]         = { .fp = sq_add_sqlite3_dateint },
		[SQLITE_NULL]    = { .fp = 0 },
	},
	{
		[SQLITE_INTEGER] = { .fp = pr_add_sqlite3_int },
		[SQLITE_FLOAT]   = { .fp = pr_add_sqlite3_double },
		[SQLITE_TEXT]    = { .fp = pr_add_sqlite3_text },
		[SQLITE_BLOB]    = { .fp = pr_add_sqlite3_blob },
		[SQLITE_NULL]    = { .fp = 0 },
	},
}; 


#if 0
//Trim any characters 
static unsigned char *trim (uint8_t *msg, char *trim, int len, int *nlen) 
{
	//Define stuff
	uint8_t *m = msg;
	int nl= len;
	//Move forwards and backwards to find whitespace...
	while ( memchr(trim, *(m + ( nl - 1 )), 4) && nl-- ) ; 
	while ( memchr(trim, *m, 4) && nl-- ) m++;
	*nlen = nl;
	return m;
}
#endif


#if 0
/*Print and set error*/
int perr (Database *gb, SQ_Error err) 
{
	struct stupid_err c = stupid_error_map[err];
	fprintf(stderr, "%s\n", c.msg);
	if (c.sys)
		fprintf(stderr, "%s\n", sqlite3_errmsg(gb->db));
	/*Varargs could pop off each of the needed arguments*/
	/*If you need to "unwind the stack", do that from the error map*/
	return 0;
}
#endif


#ifdef DEBUG_H
/*Print out the weird structure*/
void print_global (Database *gb) 
{
	stprintf("table",    gb->table);
	stprintf("filename", gb->filename);
	stprintf("sql",      gb->sql);
	spprintf("db",       (void *)gb->db);
	spprintf("stmt",     (void *)gb->stmt);
}


/*Print out the weird structure*/
void print_db (Database *gb) 
{
	stprintf("table",    gb->table);
	stprintf("filename", gb->filename);
	stprintf("sql",      gb->sql);
	spprintf("db",       (void *)gb->db);
	spprintf("stmt",     (void *)gb->stmt);
}


/*Print the type*/
void sq_print_type (SQWrite *j) 
{
	fprintf(stderr, "type: %d\n", j->type);
	fprintf(stderr, "type: %s\n", sq_names[j->type]);
}
#endif



//Where exactly is a character in memory
static int32_t Lmemchrat (const void *a, const char b, int32_t size) 
{
	_Bool stop  = 1;
	int32_t ct  = 0;// occ=0;
	uint8_t *aa = (uint8_t *)a;
	char bb[1]  = { b };
	while ((stop = (ct < size)) && memcmp(aa + ct, bb, 1) != 0) ct++;
	return (ct == size) ? -1 : ct;
}


#if 0
//Finds the 1st occurence of one char, Keep running until no tokens are found in range...
static int32_t Lmemtok (const void *a, const uint8_t *tokens, int32_t sz, int32_t tsz) 
{
	int32_t p=-1,n;
	for (int i=0; i<tsz; i++) {
		p = ((p > (n = Lmemchrat(a, tokens[i], sz)) && n > -1) || p == -1) ? n : p;
	}
	return p;
}
#endif


//Opens and creates a new database if it does not exist and closes it
_Bool sq_create_oneshot (const char *filename, const char *sql) 
{
	int rc, t = 0, a = 0;
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;

	//Open the database
	if (sqlite3_open(filename, &db) != SQLITE_OK) 
	{
		//return berr(0, ERR_DB_OPEN );
		return err(0, "failed to open db: %s\n", sqlite3_errmsg( db ));
	}

	//TODO: Add checks to make sure that there is a semicolon...
	if ( !memchr( sql, ';', strlen(sql) ) )  
	{
		//Copy statement to a buffer
		init_buf(sql, buf, a);

		//Prepare a statement
		if ((rc = sqlite3_prepare_v2(db, buf, -1, &stmt, 0)) != SQLITE_OK)
			return err(0, "failed to prepare stmt: %s\n", sqlite3_errmsg( db ));
			//return berr(0, ERR_DB_PREPARE_STMT);

		//Step to commit the record
		if ((rc = sqlite3_step(stmt)) != SQLITE_DONE) 
		{
			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return err(0, "error stepping thru db: %s\n", sqlite3_errmsg( db ));
			//return berr(0, ERR_DB_STEP);	
		}
	}
	else 
	{
		//Loop through each part of the SQL query 
		while ((a = memtok(&sql[t], (uint8_t *)";\0", strlen(sql) - t, 2)) > -1) 
		{
			init_buf(&sql[t], buf, a); 
			//write(2, &sql[t], a);
			
			//Prepare a statement
			if ((rc = sqlite3_prepare_v2(db, buf, -1, &stmt, 0)) != SQLITE_OK)
				return err(0, "error preparing db stmt: %s\n", sqlite3_errmsg( db ));
				//return berr(0, ERR_DB_PREPARE_STMT);

			//Step to commit the record
			if ((rc = sqlite3_step(stmt)) != SQLITE_DONE) 
			{
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return err(0, "error stepping through db stmt: %s\n", sqlite3_errmsg( db ));
				//return berr(0, ERR_DB_STEP);	
			}

			//Move up the indicator
			t += a + 1;
		} 
	} 

	//finalize statement 
	if (stmt)
		sqlite3_finalize(stmt);

	//close database
	if (sqlite3_close(db) != SQLITE_OK)
		return berr(0, ERR_DB_CLOSE);
	return 1;	
}



//Do an insert
int sq_insert_oneshot (const char *filename, const char *sql, const SQWrite *w) 
{
	int rc, pos = 1;
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;
	SQInsert *stack = sq_inserters[0];

	//Open database	
	if (sqlite3_open(filename, &db) != SQLITE_OK)
	{
		fprintf (stderr, "Failed to prepare db stmt: %s\n", sqlite3_errmsg(db));	
		return 0; //ERR_DB_OPEN; //berr(0, ERR_DB_OPEN);
	}

	//Prepare
	if ((rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0)) != SQLITE_OK) 
	{
		//return err(NULL, ERR_DB_PREPARE_STMT);
		fprintf (stderr, "Failed to prepare db stmt: %s\n", sqlite3_errmsg(db));	
		return 0;
	}

	//Loop through each value, do something with it
	while (!w->sentinel) 
	{
		if (!stack[w->type].fp (stmt, pos, w))
		{
			fprintf( stderr, "Insert at stack failed...\n" );
			return 0;
		}
		w++, pos++;
	}

	//Step and execute
	if ((rc = sqlite3_step(stmt)) != SQLITE_DONE)
	{
		fprintf (stderr, "Failed to step: %s\n", sqlite3_errmsg(db));	
		//return berr(0, ERR_DB_STEP);
		return 0;
	}

	//Finalize statement
	if (stmt)
		sqlite3_finalize(stmt);

	//close database
	if (sqlite3_close(db) != SQLITE_OK)
	{
		fprintf (stderr, "Failed to close db: %s\n", sqlite3_errmsg(db));	
		//return berr(0, ERR_DB_CLOSE);
		return 0;
	}

	return 1;
}




//This returns the total size of a query
int sq_get_query_size ( sqlite3_stmt *stmt ) {
	//Define stuff
	//sqlite3_stmt Stmt;
	int rc;
	int size=0;

	//serialize those results
	while ((rc = sqlite3_step(stmt)) != SQLITE_DONE) {
		for (int i=0; i < sqlite3_data_count(stmt); i++) {
			size += sqlite3_column_bytes(stmt, i);
			size += boundarySize;
		}
		//size -= 3;	
	}

	return size;
} 



//Read data and return a reference to it
uint8_t *sq_read_oneshot (const char *filename, const char *sql, int limit) 
{
	//Define common things
	int rc;
	int lm=0;
	int size=0;
	uint8_t *msg = NULL;
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;

	//open the database if it's not already (or die and open it elsewhere)
	if (sqlite3_open(filename, &db) != SQLITE_OK) {
		//return err(NULL, ERR_DB_OPEN);
		//fprintf( stderr, "%s: %s\n", name, err(ERR_DB_OPEN));   
		return NULL;
	}

	//execute whatever SQL is here
	if ((rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0)) != SQLITE_OK) {
		//return err(NULL, ERR_DB_PREPARE_STMT);
		//fprintf( stderr, "%s: %s\n", name, err(ERR_DB_PREPARE_STMT));   
		return NULL;
	}

	//Stack model should be chosen ahead of time
	SQReader *stack = sq_readers[0];

	//Create some space for the message.  Leave me alone...
	if ( !(msg = calloc(sq_get_query_size(stmt), 1)) ) {
		fprintf( stderr, "%s: %s\n", name, "Couldn't allocate space for result set.");
		return NULL;
	}

			
	//serialize those results
	while ( (rc = sqlite3_step(stmt)) != SQLITE_DONE )
	{
		int s = sqlite3_data_count(stmt);
		for (int i=0; i < s; i++) 
		{
			//TODO: realloc might be a better option here.
			int wr = sqlite3_column_bytes (stmt, i); 
			memcpy( &msg[size], sqlite3_column_text(stmt, i), wr );
			size  += wr;
	
			//Copy the next boundary	
			memcpy( &msg[size], &boundary[ (i != (s - 1)) ? 0 : 9 ], 9 );
			size  +=  9;
		}

		//fprintf(stderr, "%s\n", "hi");
		//write(2, msg, size);
		//getchar();
	}

	//finalize statement 
	if (stmt) {
		sqlite3_finalize(stmt);
	}

	//close database
	if (sqlite3_close(db) != SQLITE_OK) {
		//return err(NULL, ERR_DB_CLOSE);
		//You could theoretically try again.
		return NULL;
	}


	//Return something
	return msg;
}



//Read data and use a callback
uint8_t *sq_readinto_oneshot (const char *filename, const char *sql, int limit, void *p, int (*fp)(void *p)) 
{
	//Define common things
	int rc;
	int lm=0;
	int size=0;
	uint8_t *msg = NULL;
	sqlite3 *db = NULL;
	sqlite3_stmt *stmt = NULL;

	//open the database if it's not already (or die and open it elsewhere)
	if (sqlite3_open(filename, &db) != SQLITE_OK) {
		//return err(NULL, ERR_DB_OPEN);
		//fprintf( stderr, "%s: %s\n", name, err(ERR_DB_OPEN));   
		return NULL;
	}

	//execute whatever SQL is here
	if ((rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0)) != SQLITE_OK) {
		//return err(NULL, ERR_DB_PREPARE_STMT);
		//fprintf( stderr, "%s: %s\n", name, err(ERR_DB_PREPARE_STMT));   
		return NULL;
	}

			
	//serialize those results
	while ( (rc = sqlite3_step(stmt)) != SQLITE_DONE )
	{
		int s = sqlite3_data_count(stmt);
		for (int i=0; i < s; i++) 
		{
			//TODO: realloc might be a better option here.
			int wr = sqlite3_column_bytes (stmt, i); 
			memcpy( &msg[size], sqlite3_column_text(stmt, i), wr );
			size  += wr;
	
			//Copy the next boundary	
			memcpy( &msg[size], &boundary[ (i != (s - 1)) ? 0 : 9 ], 9 );
			size  +=  9;
		}

#if 0
		fprintf(stderr, "%s\n", "hi");
		write(2, msg, size);
		getchar();
#endif
	}

	//finalize statement 
	if (stmt) {
		sqlite3_finalize(stmt);
	}

	//close database
	if (sqlite3_close(db) != SQLITE_OK) {
		//return err(NULL, ERR_DB_CLOSE);
		//You could theoretically try again.
		return NULL;
	}


	//Return something
	return msg;
}






//Check type
SQType sq_get_type (uint8_t *p, int len) {
	char c=0, f=0;
	int d=0, start=0, end=len;

	//Chop whitespace from front
	if (p[d] == 32 || p[d] == 9) {
		for (d=0; d <= len; ++d)
			if ((start = ((int)p[d] != 32) ? d : 0)) break;
		//Catch strings composed entirely of whitespace
		if (d == len)
			return 0;
	}
	else {
		start = 0;
	}

	//Chop whitespace from back 
	//fprintf(stderr, "p[len]: %d\n", (int)p[len]);
	if ((int)p[len] == 0 && ((int)p[len - 1] == 32 || (int)p[len - 1] == 9)) {
		for (d=len - 1; d > start; d--) {
			//fprintf(stderr, "%d\n", d);
			int pp = p[d];	
			if ((end = (pp != 32 && pp != 9 && pp != 0) ? d : 0)) break;
		}
	}

	//Loop
	for ( int i=start; i < end; i++ )	{
		int ii = (int)p[i];

		//check uint8_t
		if ( ii > 127 || (ii < 32 && ii != 10 && ii != 9 ) ) {
			return SQ_BLB;     
		}
		//check int or float
		else if ((ii > 47 && ii < 58 ) || ii == 46 ) {
			if (ii == 46)
				f = 1;
			if (i == (end - 1)) {
				return (!f) ? SQ_INT : SQ_FLT;	
			}	
		}
		//check string
		else if ( (ii > 31 && ii < 127) || ii == 10 || ii == 9 ) {
			return SQ_TXT;
		}
	}
	return 0;
}






/*The cursor or current row can be kept here*/
static _Bool sq_add_sqlite3_int (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	int rc = sqlite3_bind_int( stmt, i, w->v.n );
	if (rc != SQLITE_OK) {
		return (fprintf(stderr, "Error binding SQL %s at position %d: %s\n",
			sqltypes[SQLITE_INTEGER], i, sqlite3_errstr(rc)) ? 0 : 0);
	}
	return 1;
}



//Add a date by integer or by long date?
static _Bool sq_add_sqlite3_dateint (sqlite3_stmt *stmt, int i, const SQWrite *w) {
 #ifdef _POSIX_TIME 
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
 #else
	struct timeval ts;
	gettimeofday( &ts, NULL );
 #endif
	int rc = sqlite3_bind_int( stmt, i, ts.tv_sec );
	if (rc != SQLITE_OK) {
		return (fprintf(stderr, "Error binding SQL %s at position %d: %s\n",
			sqltypes[SQLITE_INTEGER], i, sqlite3_errstr(rc)) ? 0 : 0);
	}
	return 1;
}



//
static _Bool sq_add_sqlite3_double (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	int rc=sqlite3_bind_double(stmt, i, w->v.f);
	if (rc != SQLITE_OK) {
		return (fprintf(stderr, "Error binding SQL %s at position %d: %s\n",
			sqltypes[SQLITE_FLOAT], i, sqlite3_errstr(rc)) ? 0 : 0);
	}
	return 1;
}


static _Bool sq_add_sqlite3_text (sqlite3_stmt *stmt, int i, const SQWrite *w) 
{
	int rc= sqlite3_bind_text(stmt, i, w->v.c,
		(!w->len || w->len == -1) ? strlen(w->v.c) : w->len, SQLITE_STATIC);
	if (rc != SQLITE_OK) {
		return (fprintf(stderr, "Error binding SQL %s at position %d: %s\n",
			sqltypes[SQLITE_TEXT], i, sqlite3_errstr(rc)) ? 0 : 0);
	}
	return 1;
}


static _Bool sq_add_sqlite3_blob (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	int rc = sqlite3_bind_blob(stmt, i, w->v.d, w->len, SQLITE_STATIC);
	if (rc != SQLITE_OK) {
		return (fprintf(stderr, "Error binding SQL %s at position %d: %s\n",
			sqltypes[SQLITE_BLOB], i, sqlite3_errstr(rc)) ? 0 : 0);
	}
	return 1;
}


static _Bool pr_add_sqlite3_int (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	fprintf(stderr, "Adding int at column %d\n", i);
	fprintf(stderr, "%d\n", w->v.n); 
	return 1;
}


static _Bool pr_add_sqlite3_double (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	fprintf(stderr, "Adding float at column %d\n", i);
	fprintf(stderr, "%f\n", w->v.f); 
	return 1;
}


static _Bool pr_add_sqlite3_text (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	fprintf(stderr, "Adding text at column %d\n", i);
	write(2, w->v.c, w->len);
	return 1;
}


static _Bool pr_add_sqlite3_blob (sqlite3_stmt *stmt, int i, const SQWrite *w) {
	fprintf(stderr, "Adding blob at column %d\n", i);
	write(2, w->v.d, w->len);
	return 1;
}


/*Handles serializing everything*/
static int sq_sqlite3_column_int (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%s\n", sqlite3_column_text(stmt, col)); 
	return 1;
}


static int sq_sqlite3_column_double (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%s\n", sqlite3_column_text(stmt, col)); 
	return 1;
}


static int sq_sqlite3_column_text (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%s\n", sqlite3_column_text(stmt, col)); 
	return 1;
}


static int sq_sqlite3_column_blob (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%s\n", sqlite3_column_text(stmt, col)); 
	return 1;
}


/*Get size of items in columns everything*/
static int sz_sqlite3_column_any (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	return sqlite3_column_bytes(stmt, col); 
}


/*Handles serializing everything*/
static int pr_sqlite3_column_int (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%d\n", sqlite3_column_int(stmt, col)); 
	return 1;
}

static int pr_sqlite3_column_double (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%f\n", sqlite3_column_double(stmt, col)); 
	return 1;
}

static int pr_sqlite3_column_text (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "%s\n", sqlite3_column_text(stmt, col)); 
	return 1;
}

static int pr_sqlite3_column_blob (sqlite3_stmt *stmt, int col, uint8_t *msg) {
	fprintf(stderr, "bytes: %d\n", sqlite3_column_bytes(stmt, col)); 
	write(2, sqlite3_column_blob(stmt, col), sqlite3_column_bytes(stmt, col)); 
	return 1;
}







/*Write a date*/
void sq_getdate (char *datebuf) {
	struct tm *tm;
	time_t t = time(NULL);

	/*Get the current date and time*/
	if (!(tm = localtime(&t)))
		return;

	strftime(datebuf, 256, "%a, %d %b %Y %T %z", tm);
}



/*Initialize a database structure*/
_Bool sq_init (Database *gb) {
	memset(gb, 0, sizeof(Database));
	gb->filename = NULL;
	gb->sql      = NULL;
	gb->table    = NULL;
	gb->qname    = NULL;
	gb->db       = NULL;
	gb->stmt     = NULL;
	gb->error    = 0;
	gb->read_started = 0;
	memset( &gb->header, 0, sizeof( Buffer ));
	memset( &gb->results, 0, sizeof( Buffer ));
	memset( &gb->kvt, 0, sizeof( Table ));
	return 1;
}


/*Open a database and leave it open*/
_Bool sq_open (Database *gb, const char *filename) 
{
	//Initialize this
	memset(gb, 0, sizeof(Database));
	gb->stmt     = NULL;
	gb->sql      = NULL;
	gb->table    = NULL;
	gb->db       = NULL;
	gb->filename = NULL;

	//Then open the database and return a handle
	if (sqlite3_open(filename, &gb->db) != SQLITE_OK)  
	{
		fprintf(stderr, "%s\n", sqlite3_errmsg(gb->db) );
		return 0;
	}

#ifdef SQ_VERBOSE
	fprintf( stderr, "Opening SQLITE database: %s\n", filename );
#endif
	return 1;
}



//Executes a SQL statement
_Bool sq_exec (Database *gb, const char *sql) 
{
	/*Finalize if not already done*/
	(gb->stmt) ? sqlite3_finalize(gb->stmt) : 0;

	/*This is some silly shit here*/
	int t = 0, a = 0, rc = 0;
	while ((a = memtok(&sql[t], (uint8_t *)";\0", strlen(sql) - t, 2)) > -1) 
	{
		//Initialize a buffer
		init_buf(&sql[t], buf, a); 
		
		//Prepare a statement
		if ((rc = sqlite3_prepare_v2(gb->db, buf, -1, &gb->stmt, 0)) != SQLITE_OK)
		{
			sq_free( gb );
			return berr(0, ERR_DB_PREPARE_STMT);
		}

		//Step to commit the record
		if ((rc = sqlite3_step(gb->stmt)) != SQLITE_DONE) 
		{
			sqlite3_finalize(gb->stmt);
			sq_free( gb );
			return berr(0, ERR_DB_STEP);	
		}

		//Move up the indicator
		t += a + 1;
	} 

	//Finalize b/c we're finished
	sqlite3_finalize(gb->stmt);
	gb->stmt = NULL;
	return 1;	
}



//Insert values with a SQL statement that needs to be bound
_Bool sq_exec_complex (Database *gb, const char *sql, const SQWrite *w) 
{
	int rc, pos = 1;
	SQInsert *stack = sq_inserters[0];

	//Prepare
	if ((rc = sqlite3_prepare_v2(gb->db, sql, -1, &gb->stmt, 0)) != SQLITE_OK) {
		fprintf(stderr, "errerr: %s\n", sqlite3_errmsg(gb->db));
		return 0; //err(NULL, ERR_DB_PREPARE_STMT);
	}

	//Loop and bind each value
	while (!w->sentinel) {
		if (!stack[w->type].fp (gb->stmt, pos, w))
			return 0;
		w++, pos++;
	}

	//Step and execute
	if ((rc = sqlite3_step(gb->stmt)) != SQLITE_DONE) {
		return 0;//err(NULL, ERR_DB_STEP);
	}

	//Finalize statement
	if (gb->stmt) {
		sqlite3_finalize(gb->stmt);
		gb->stmt = NULL;
	}

	return 1;
}
/*Close a database and finalize any prepared statement*/
_Bool sq_close (Database *gb) 
{
	(gb->stmt) ? sqlite3_finalize(gb->stmt) : 0;
	lt_free( &gb->kvt );
	bf_free( &gb->header );
	bf_free( &gb->results );
	free( gb->qname );
	return (sqlite3_close(gb->db) != SQLITE_OK) ? berr(0, ERR_DB_CLOSE) : 1;
}



/*Starts reading from a set of results, subsequent calls will get next result*/
_Bool sq_read (Database *gb, const char *sql) 
{
	(gb->stmt) ? sqlite3_finalize(gb->stmt) : 0;

	if (!gb->read_started) {
		if (sqlite3_prepare_v2(gb->db, sql, -1, &gb->stmt, 0) != SQLITE_OK) 
		{
			sq_free( gb );
			return berr(0, ERR_DB_PREPARE_STMT);
		}
		gb->read_started = 1;
	}

	if (sqlite3_step(gb->stmt) != SQLITE_DONE) {
		gb->read_started = 0;
		return 0; 
	}
	return 1;
}



/*Finds a specific value in a row of an open database handle*/
int sq_find (Database *gb, const char *colname) {
	int cc = sqlite3_data_count(gb->stmt);
	for (int i=0; i<cc; i++)  {
		if (strcmp(sqlite3_column_name(gb->stmt, i), colname) == 0) {
			return i;
		} 
	}
	return -1;
}


const char *sq_strerror ( Database *db )
{
	return NULL; //stupid_error_map[ db->error ].msg;
} 


//just prints one row
void sq_write_value_print (SQWrite *w) {
	switch (w->type) {
		case SQ_INT:
			fprintf(stderr, "%d", w->v.n);
			break;
		case SQ_FLT:
			fprintf(stderr, "%d", w->v.n);
			break;
		case SQ_TXT:
			fprintf(stderr, "%d", w->v.n);
			break;
		case SQ_BLB:
			write(2, w->v.d, w->len);	
			break;
		case SQ_NUL:
			fprintf(stderr, "(null)");
			break;
		case SQ_DTE:
			break;
		default:
			fprintf(stderr, "Unknown value received");
			break;
	}
	fprintf(stderr, "\n");
	fprintf(stderr, "last value: %s\n", w->sentinel ? "true" : "false");
}



//....
void sq_write_print (Database *gb, SQWrite *w) {
	SQReader *stack = sq_readers[1];
	int i=0;
	while (!w->sentinel) {
		if (!stack[w->type].fp (gb->stmt, i, NULL))
			return;
		w++, i++;
	}
}



//Insert values with a SQL statement that needs to be bound
_Bool sq_insert (Database *gb, const char *sql, const SQWrite *w) 
{
	int rc, pos = 1;
	SQInsert *stack = sq_inserters[0];

	//Prepare
	if ((rc = sqlite3_prepare_v2(gb->db, sql, -1, &gb->stmt, 0)) != SQLITE_OK) {
		fprintf(stderr, "errerr: %s\n", sqlite3_errmsg(gb->db));
		return 0; //err(NULL, ERR_DB_PREPARE_STMT);
	}

	//Loop and bind each value
	while (!w->sentinel) {
		if (!stack[w->type].fp (gb->stmt, pos, w))
			return 0;
		w++, pos++;
	}

	//Step and execute
	if ((rc = sqlite3_step(gb->stmt)) != SQLITE_DONE) {
		return 0;//err(NULL, ERR_DB_STEP);
	}

	//Finalize statement
	if (gb->stmt) {
		sqlite3_finalize(gb->stmt);
		gb->stmt = NULL;
	}

	return 1;
}



//a reader: starts, runs and ends 
_Bool sq_reader_start (Database *gb, const char *sql, const SQWrite *w) 
{
	//Finalize
	if (gb->stmt) {
		sqlite3_finalize(gb->stmt);
		gb->stmt = NULL;
	}	

	if (sqlite3_prepare_v2(gb->db, sql, -1, &gb->stmt, 0) != SQLITE_OK) {
		sq_free( gb );
		return berr(0, ERR_DB_PREPARE_STMT);
	}

	//Loop and bind each value if you gave it something
	if (w) {
		int pos = 1;
		SQInsert *stack = sq_inserters[0];
		while (!w->sentinel) {
			if ( !stack[w->type].fp (gb->stmt, pos, w) )
				return 0;
			w++, pos++;
		}
	}
	return 1;
}



//move to the next set, until there's nothing left
_Bool sq_reader_continue (Database *gb) {
	return (sqlite3_step(gb->stmt) != SQLITE_DONE) ? 1 : 0;
}



//Finds a specific value in a row
int sq_reader_find (Database *gb, const char *colname) {
	int cc = sqlite3_data_count(gb->stmt);
	//SQReader *stack = sq_readers[XSTMT];
	//fprintf(stderr, "rows: %d\n", cc);
	for (int i=0; i<cc; i++)  {
		//fprintf(stderr, "%s - %s\n", sqlite3_column_name(gb->stmt, i), colname);
		if (strcmp(sqlite3_column_name(gb->stmt, i), colname) == 0) {
			//fprintf(stderr, "'%s' matches\n", colname);
			//stack[ sqlite3_column_type(gb->stmt, i) ].fp(gb->stmt, i); 
			return i;
		} 
	}
	return -1;
}


//Save database results to table
int sq_save (Database *db, const char *query, const char *name, const SQWrite *w )
{
	//...
	int len = 0;
	//define a name for model (if you want one)
	const char *pq = NULL;

	//Shut down attempts to send null queries
	if ( !query ) {
		fprintf( stderr, "No query specified...\n" );
		return 0;
	}

	//Shut down attempts to read unopened databases
	if ( !db ) {
		fprintf( stderr, "No open database was detected...\n" );
		return 0;
	}



	//Trim the received query
	pq = (char *)trim((uint8_t *)query, " \t\n\r", strlen(query), &len ); 

	//Run any other statement
	if ( !memchr( "sS", *pq, 2 ) ) 
	{
		if ( !sq_exec_complex ( (Database *)db, pq, w ) ) 
		{
			fprintf( stderr, "sql_wrap: Failed to execute complex query.\n" );
			return 0;
		}
	}
	//Run selects
	else
	{
		//Set the hash table's source to point the buffer's data
		char *columnNames[127] = { NULL };
		int columnInts[127]    = { 0 };
		int pos         = 0,
		    columnCount = 0,
		    bfw         = 0, 
		    a           = 0, 
		    title       = 0; 
		uint8_t *src    = NULL;
		Parser q = { .words={
			{ (char *)sqlite3_E },
			{ (char *)sqlite3_C },
			{ (char *)sqlite3_N },
			{ NULL }
		}};

		//Initialize buffer for column names
		if ( !bf_init( &db->header, NULL, 1 ) ) {
			fprintf( stderr, "bf_init failed...\n" );
			return 0;
		}

		//Initialize buffer for result set
		if ( !bf_init( &db->results, NULL, 1 ) ) {
			fprintf( stderr, "initialization of results failed...\n" );
			return 0;
		}

		//Initialize a Table for result viewing 
		if ( !lt_init( &db->kvt, NULL, 1024 ) ) 
		{
			fprintf( stderr, "bf_init failed...\n" );
			return 0;
		}
	
		//Start reading
		if ( !sq_reader_start ( (Database *)db, pq, !w ? nullw : w ) ) {
			fprintf( stderr, 	"start failed...\n" );
			return 0;//http_err( h, 404, "Page not found." );
		}

		//Unless there are a ton of columns, we should be fine with this.
		if (( columnCount = sqlite3_column_count( db->stmt )) > 127 ) {
			fprintf( stderr, "sql_wrap: Too many rows...\n" );
			return 0;
		}


		//Add each of the keys to the top of the table
		for (int i=0; i < columnCount; i++ )
		{
			uint8_t *name = (uint8_t *)sqlite3_column_name(db->stmt, i);
			int len = strlen( (char *)name );
			if ( !bf_append( &db->header, name, len ) ) {
				fprintf( stderr, "sql_wrap: Failed to add key names.\n" );
				return 0;
			}
			if ( !bf_append( &db->header, (uint8_t *)"\0", 1 ) ) { 
				fprintf( stderr, "sql_wrap: Failed to add sep.\n" );
				return 0;
			}
			columnInts[ i ] = pos;
			pos += len + 1;
		}

		for (int i=0; i < columnCount; i++ )
			columnNames[i] = (char *)&(&db->header)->buffer[ columnInts[i] ];	

		//This expects just one file
		while ( sq_reader_continue( (Database *)db ) ) 
		{
			int dc = sqlite3_data_count(db->stmt);
			//If there were no results
			if ( !dc ) {
				//lt_free( &db->header );
				sq_close( (Database *)db );
				return 0;
			}

			/*Using a hash table is such a good call*/
			for (int i = 0; i < dc; i++ ) 
			{
				//All of the templates could go together here if you were so inclined
				int len    = sqlite3_column_bytes(db->stmt, i);
				uint8_t *b = (uint8_t *)sqlite3_column_blob(db->stmt, i); 
				uint8_t *c = (i == dc - 1) ? (uint8_t *)sqlite3_N : (uint8_t *)sqlite3_C;

				//Add value to buffer
				if ( !bf_append( &db->results, b, sqlite3_column_bytes(db->stmt, i)) )
				{
					fprintf( stderr, "sql_wrap: Failed to add result set.\n" );
					return 0;
				}

				if ( !bf_append( &db->results, c, sqlite3_L ) ) {
					fprintf( stderr, "sql_wrap: Failed add sep.\n" );
					return 0;
				}
			}
		}

		//Mark the end
		bf_append( &db->results, (uint8_t *)"\0", 1 );
		src = bf_data( &db->results );
		bfw = bf_written( &db->results );
		memset( &src[ bfw - ( sqlite3_L + 1 ) ], '3', sqlite3_L );

		//Set everything needed for parsing
		pr_prepare( &q );

		//Add a query name (free it later)
		if ( name ) 
		{
			db->qname = malloc( strlen( name ) + 1 );
			memset( db->qname, 0, strlen( name ) + 1 );
			memcpy( db->qname, name, strlen( name ) );
			//db->qname[ strlen( name ) ] = '\0';
			lt_addblobkey( &db->kvt, (uint8_t *)db->qname, strlen( name ) );
			lt_descend( &db->kvt );
		}

		lt_addintkey( &db->kvt, title );
		lt_descend( &db->kvt );


		//Loop through all and put them in a malloc'd area.
		while ( pr_next( &q, src, bfw ) )
		{
			lt_addblobkey( &db->kvt, (uint8_t *)columnNames[a], strlen( columnNames[a] ));
			lt_addblobvalue( &db->kvt, &src[ q.prev ], q.size );
			lt_finalize ( &db->kvt );
			( a == columnCount - 1 ) ? a = 0 : a++;

			if ( !q.word )
				break;
			else if ( *q.word == '3' )
			{
				lt_ascend( &db->kvt );
				break;
			}
			else if ( *q.word == '{' ) 
			{
				lt_ascend( &db->kvt );
				lt_addintkey( &db->kvt, ++title );
				lt_descend( &db->kvt );
			}
		}

		if ( name ) {
			lt_ascend( &db->kvt );
		}
	}

	lt_lock( &db->kvt );
	//lt_printall ( &db->kvt );
	return 1;	
}
#endif


#ifndef RAND_H
Random __rs;
static const struct { char *str; int len; } __rsdata[] = {
	{	"!\"#$%&'(),-./:;<=>?@[\\]^_`{|}~", 30 },
	{	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdef"
		"ghijklmnopqrstuvwxyz"            , 52 },
	{	"0123456789"                      , 10 },
	{	"0123456789ABCDEFGHIJKLMNOPQRSTUV"
  	"WXYZabcdefghijklmnopqrstuvwxyz"  , 62 },
	{	"0123456789ABCDEFGHIJKLMNOPQRSTUV"
  	"WXYZabcdefghijklmnopqrstuvwxyz!#"
		"\"$%&'(),-./:;<=>?@[\\]^_`{|}~"  , 92 }
};


//Get a random seed
static int rand_seed_ctime (void)  {
 #ifdef LITE_MT
	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	srand ( (unsigned) ts.tv_nsec );
 #else
	clock_gettime(CLOCK_REALTIME, &__rs.rand_ts);
	srand ( (unsigned) __rs.rand_ts.tv_nsec );
 #endif
	return 1;
}


//Feed to a stream
static char *rand_stream
#ifdef LITE_MT
 (Random *t, int type, int length)
#else
 (int type, int length) 
#endif
{
	memset(__rs.buf, 0, RAND_BUF_SIZE);
	rand_seed_ctime();
	int len = length < RAND_BUF_SIZE ? length : RAND_BUF_SIZE;
	for (int i=0; i<len; i++)
	{
	#ifdef LITE_MT
	#else
		__rs.buf[i] = __rsdata[type].str[( rand() % __rsdata[type].len )];
	#endif	
	}
	return __rs.buf;
}

//Return a random integer
int rand_number(void) {
	return (rand_seed_ctime()) ? rand() : 0;
}


//Return a string full of random punctuation 
char * rand_punct
#ifdef LITE_MT
 (Random *t, int length)
#else
 (int length) 
#endif
{
 #ifdef LITE_MT
	return NULL;
 #else
	return rand_stream(0, length);
 #endif
}


//Return a string full of random numbers
char * rand_numbers
#ifdef LITE_MT
 (Random *t, int length)
#else
 (int length) 
#endif
{
 #ifdef LITE_MT
	return NULL;
 #else
	return rand_stream(2, length);
 #endif
}


//Return a string full of random alphanumeric characters
char * rand_alnum
#ifdef LITE_MT
 (Random *t, int length)
#else
 (int length) 
#endif
{
 #ifdef LITE_MT
	return NULL;
 #else
	return rand_stream(3, length);
 #endif
}


//Return a string full of random alphabetical characters
char * rand_chars
#ifdef LITE_MT
 (Random *t, int length)
#else
 (int length) 
#endif
{
 #ifdef LITE_MT
	return NULL;
 #else
	return rand_stream(1, length);
 #endif
}

//Return a random string full of a = (ASCII characters), where 32 < a < 127
char * rand_any
#ifdef LITE_MT
 (Random *t, int length)
#else
 (int length) 
#endif
{
 #ifdef LITE_MT
	return NULL;
 #else
	return rand_stream(4, length);
 #endif
}
#endif


#ifndef TIMER_H
static const unsigned long CV_1T = 1000;
static const unsigned long CV_1M = 1000000;
static const unsigned long CV_1B = 1000000000;

//Initiailize a timer
void __timer_init (Timer *t, LiteTimetype type) 
{
	memset(t, 0, sizeof(Timer));	
	t->type = type;
}


//Set the name of a timer
void __timer_set_name (Timer *t, const char *label) 
{
	t->label = label;
}


//Start a currently running timer
 #ifndef CV_VERBOSE_TIMER 
void __timer_start (Timer *t)
{
 #else
void __timer_start (Timer *t, const char *file, int line)
{
	t->file = file;
	t->linestart = line;
 #endif 
	t->clockid = CLOCK_REALTIME;
	clock_gettime( t->clockid, &t->start );
}


//Stop a currently running timer
 #ifndef CV_VERBOSE_TIMER 
void __timer_end (Timer *t)
{
 #else
void __timer_end (Timer *t, const char *file, int line)
{
	t->file = file;
	t->lineend = line;
 #endif 
	clock_gettime( t->clockid, &t->end );
}


//Returns difference of start and end time
int __timer_elap (Timer *t) 
{
	return t->end.tv_sec - t->start.tv_sec;
}


//Pretty prints difference in requested format of start and end time
void __timer_eprint (Timer *t) 
{
	//Define some stuff...
	unsigned long nsdiff = 0;
	time_t secs = 0;
	double mod = 0;
	char ch[64] = { 0 };
	const char *ts ;
	const char *time   = "ns\0ms\0us\0s";
	const char *label  = (t->label) ? t->label :
	 #ifdef CV_VERBOSE_TIMER
		(t->file) ? t->file : "anonymous"
	 #else
		"anonymous"
	 #endif
	;
	const char *fmt    =
   #ifdef CV_VERBOSE_TIMER
	  //"routine @[ %-20s %d - %d ] completed in %11ld %s\n"
	  "routine @[ %-20s %d - %d ] completed in %s %s\n"
   #else
	  "routine [ %-20s ] completed in %s %s\n"
   #endif
	;


	//Get the raw elapsed seconds and nanoseconds
	if ((secs = t->end.tv_sec - t->start.tv_sec) == 0)
		nsdiff = t->end.tv_nsec - t->start.tv_nsec;
	else if (secs < 0) 
	{
		fprintf(stderr, "Timer error occurred!\n");
		return; /*Some kind of error occurred*/
	}
	else if (secs > 0) 
	{
		if ((nsdiff = (CV_1B - t->start.tv_nsec) + t->end.tv_nsec) > CV_1B) {
			nsdiff -= CV_1B;
			secs += 1;
		}
	}


	//Choose a modifier and make any final calculations for formatting
	switch (t->type) 
	{
		case LITE_NSEC:   //0.000,000,001
			snprintf( ch, 64,  "%ld", nsdiff );
			ts = &time[0];
			break;
		case LITE_USEC:   //0.000,001
			mod = ((float)secs * CV_1M) + (((float)nsdiff / (float)CV_1B) * (float)CV_1M);
			ts = &time[6];
			snprintf( ch, 64, "%.6f", mod);
			break;
		case LITE_MSEC:   //0.001
			mod = ((float)secs * CV_1T) + (((float)nsdiff / (float)CV_1B) * (float)CV_1T);
			ts = &time[3];
			snprintf( ch, 64, "%.6f", mod);
			break;
		case LITE_SEC:
			mod = ((float)secs + ((float)nsdiff / (float)CV_1B));
			ts = &time[9];
			snprintf( ch, 64, "%.6f", mod);
			break;
		default:
			return;
	}

	fprintf(stderr, fmt, label, ch, ts); 
}
#endif


#ifndef SOCKET_H
//Get the address information of a socket.
void socket_addrinfo (Socket *sock)
{
	fprintf(stderr, "%s\n", "Getting address information for socket.");

	struct addrinfo *peek; 
	struct sockaddr_in *ipv4;
	struct sockaddr_in6 *ipv6;
	int status = getaddrinfo(sock->hostname, sock->portstr, &sock->hints, &sock->res);
	if (status != 0)
		err(1, "Could not get address information for this socket.");

	/* Loop through each */
	for (peek = sock->res; peek != NULL; peek = peek->ai_next) {
		void *addr;	
		char *ipver;
		if (peek->ai_family == AF_INET) {
			ipv4 = (struct sockaddr_in *)peek->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		else {
			ipv6 = (struct sockaddr_in6 *)peek->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv4";
		}

		if (inet_ntop(peek->ai_family, addr, sock->address, sizeof(sock->address)) == NULL)
			continue;
	
		fprintf(stderr, "%s: %s\n", ipver, sock->address);
		/* Break somewhere after finding a valid address. */
		break;
	}

	/* Free this */
	freeaddrinfo(peek);

	/* A list will probably be used here */
	// OBJECT(list) *addresses
	// { .ipver = 4, ipstr = 192.10..., .ipbin = peek->ai_addr, .len = peek->ai_addrlen }
}



//initialize a socket...
_Bool socket_open (Socket *sock) 
{
	//All of this can be done with a macro
	sock->addrsize = sizeof(struct sockaddr);
	sock->bufsz = !sock->bufsz ? 1024 : sock->bufsz;
	sock->opened = 0;
	sock->backlog = 500;
	sock->waittime = 5000;  // 3000 microseconds

	if (!sock->proto || !strcmp(sock->proto, "TCP") || !strcmp(sock->proto, "tcp"))
		set_sockopts(SOCK_STREAM, PF_INET, IPPROTO_TCP);
	else if (!strcmp(sock->proto, "udp") ||!strcmp(sock->proto, "UDP"))
		set_sockopts(SOCK_DGRAM, PF_INET, IPPROTO_UDP);

	/* Check port number (clients are zero until a request is made) */
	if (!sock->port || sock->port < 0 || sock->port > 65536) {
		return err( 1, "Invalid port specified." );
	}


	/* Set up the address data structure for use as either client or server */	
	if (sock->_class == 's') 
	{
		/*there must be a way to do this WITHOUT malloc*/
		//if ((sock->srvaddrinfo = (struct sockaddr_in *)nalloc(sizeof(struct sockaddr_in), "sockaddr.info")) == NULL)
		//	return;
			//return errnull("Could not allocate structure specified.");

		/*This ought to work...*/
		sock->srvaddrinfo = &sock->tmpaddrinfo;
		memset(sock->srvaddrinfo, 0, sizeof(struct sockaddr_in));
		struct sockaddr_in *saa = sock->srvaddrinfo; 
		saa->sin_family = AF_INET;
		saa->sin_port = htons(sock->port);
		(&saa->sin_addr)->s_addr = htonl(INADDR_ANY);
	}
	else if (sock->_class == 'c') 
	{
		/* Set up the addrinfo structure for a future client request. */
		struct addrinfo *h; 
		memset(&sock->hints, 0, sizeof(sock->hints));
		h = &sock->hints;
		h->ai_family = sock->domain;
		h->ai_socktype = sock->conntype;
	}

	/* Finally, create a socket. */
	if ((sock->fd = socket(sock->domain, sock->conntype, sock->protocol)) == -1) {
		return 0;
	}
	sock->opened = 1;

	/* Set timeout, reusable bit and any other options */
	struct timespec to = { .tv_sec = 2 };
	if (setsockopt(sock->fd, SOL_SOCKET, SO_REUSEADDR, &to, sizeof(to)) == -1) {
		// sock->free(sock);
		sock->err = errno;
		return (0, "Could not reopen socket.");
	}
	return 1;
}



//Bind to a socket
_Bool socket_bind (Socket *sock) {
	//set errno
	return (bind(sock->fd, (struct sockaddr *)sock->srvaddrinfo, sizeof(struct sockaddr_in)) != -1);
//		return errsys("Could not bind to socket.");
}



//Listen for connections over a socket.
_Bool socket_listen (Socket *sock)
{
	//set errno
	return (listen(sock->fd, sock->backlog) != -1);
		//return errsys("Could not listen out on socket.");
}



//Open a socket for UDP
_Bool socket_udp_recv (Socket *self)  {
#if 0
		case SOCK_DGRAM:
			rcvd = recvfrom(sock->fd, msg, ws, 0,
				NULL, NULL);
				//sock->cliaddr, &sock->cliaddrlen);
			if (rcvd == -1) return 0;
			msg[rcvd] = 0;
			fprintf(stderr, "udp recv'd bytes: %d\n", rcvd);
			fprintf(stderr, "%s\n", msg);	
			while (1) {
				rcvd = recvfrom(sock->fd, msg, ws, 0,
					NULL, NULL);
				fprintf(stderr, "udp recv'd bytes: %d\n", rcvd);
				fprintf(stderr, "%s\n", msg);	
				if (rcvd == -1)
					return 0;  // return false and sock->error = errno;
				if (rcvd < ws)
					break;	
			}
			return 1;
#endif
	return 0;
}



//Opens a non blocking socket.
//This function is not a good idea for select I don't think...
_Bool socket_tcp_recv (Socket *sock, uint8_t *msg, int *len) 
{
	int t = 0, 
      r = 0, 
      w = ( *len > 0 ) ? *len : 64;

	//If it's -1, die.  If it's less than buffer, die
	while (1) 
	{
		//Error occurred, free or reset the buffer and die
		if ( (r = read(sock->fd, &msg[ t ], w )) == -1 )
		{
			//handle recv() errors...
			sock->err = errno;
			return 0;
		}

		//...
		if ( !r )
		{
			fprintf( stderr, "socket_tcp_recv should be done...\n" );
			break;
		}

		t += r;
	}

	*len = t;
	return 1;
}



#if 0
_Bool socket_udp_send (Socket *sock, uint8_t *msg, uint32_t len) {
	int bs=0; 
#if 0
	bs = sendto(sock->fd, msg, msglen, 0, 
		(struct sockaddr *)sock->srvaddrinfo, 
		sizeof(struct sockaddr_in)); 
	fprintf(stderr, "Size of message to be sent: %d\n", msglen);
	fprintf(stderr, "Message to be sent:\n %s\n", msg);
	fprintf(stderr, "(press enter to continue...)\n");
	getchar();	
#endif
	bs = sendto(sock->fd, msg, len, 0, 
		(struct sockaddr *)sock->cliaddrinfo, 
		sizeof(sock->cliaddr)); 
	if (bs == -1)
		return 0;
	fprintf(stderr, "Sent UDP bytes: %d\n", bs);
	fprintf(stderr, "Sent message:   %s\n", msg);
#if 0
	while (1) {
		if (bs==msglen)
			break;
		if (bs == -1)
			return 0;
	
		fprintf(stderr, "Sent UDP bytes: %d\n", bs);
		pprintf("..>");
	}
#endif
	return 1;
}
#endif



#if 0
_Bool socket_tcp_send (Socket *sock, uint8_t *msg, uint32_t len) {
	/* What is going on? */
	int bs = 0;
#if 0
	fprintf(stderr, "Attempting to send message over fd '%d'\n", sock->fd);
	fprintf(stderr, "message contents:\n");
		
	int c = 0;
	// chardump(msg, ws > rcvd ? rcvd : ws);
	for (c=0;c<msglen;c++)
		fprintf(stderr, "'%c' ", msg[c]);
#endif
	while (1) { 
		bs = send(sock->fd, msg, len, 0);
		// usleep(sock->waittime);
		if (bs==len)
			break;
		if (bs == -1)
			return 0;
		// keep trying
	}
	return SUCCESS;
}
#endif



//Accept connections
_Bool socket_accept (Socket *sock, Socket *new) {
	/* Clone current socket data */
	if (!memcpy(new, sock, sizeof(Socket))) {
		fprintf(stderr, "Could not copy original parent socket data.\n");
		return 0;
	}

	/* Accept a connection. */	
	if ((new->fd = accept(sock->fd, NULL, NULL)) == -1) 
		return ((sock->err = errno) ? 0 : 0);
		
	/* Set socket description */
	new->_class = 'd';
	return 1;
}



//Send data via UDP
_Bool socket_udp_send (Socket *sock, uint8_t *msg, uint32_t length) {
	//int msglen = (!length) ? strlen(msg) : length;	
	int32_t bs = 0;
#if 0
	bs = sendto(sock->fd, msg, msglen, 0, 
		(struct sockaddr *)sock->srvaddrinfo, 
		sizeof(struct sockaddr_in)); 
	fprintf(stderr, "Size of message to be sent: %d\n", msglen);
	fprintf(stderr, "Message to be sent:\n %s\n", msg);
	fprintf(stderr, "(press enter to continue...)\n");
	getchar();	
#else
	bs = sendto(sock->fd, msg, length, 0, 
		(struct sockaddr *)sock->cliaddrinfo, 
		sizeof(sock->cliaddr)); 
#endif

	if (bs == -1) {
		sock->err = errno;
		return 0;
	}

	fprintf(stderr, "Sent UDP bytes: %d\n", bs);
	fprintf(stderr, "Sent message:   %s\n", msg);
#if 0
	while (1) {
		if (bs==msglen) break;
		if (bs == -1) return 0;
		fprintf(stderr, "Sent UDP bytes: %d\n", bs);
	}
#endif
	return 1;
}



#if 0
//Parse URI
_Bool socket_parse_uri (URIData *u, const char *uri) {
	int p, len=strlen(uri);
	//Pack protocol
	if (!memstr(uri, "://", len)) return 0;
	memcpy(u->protocol, 0, (p = memstrat(uri, "://", len)));
	//Check for a port (that's the end of host)
	if (!memchr(&uri[p+3], '/', len - (p+3)))
		if ((p = memchrat(&uri[p+3], ':', len - (p+3)))) {
		//Pack hostname if you can find it
	else {
	}	
	//Pack port
	return 1;
}
#endif


//Get address info
_Bool socket_getaddrinfo (Socket *self) {
	return 0;
}


//Refactor this to split out the connect steps.  Maybe create an iterator?
int socket_connect (Socket *self, const char *uri, int port) 
{
	int fd, stat;
	char *ps;
	char portstr[ 5 ] = {0};
	struct addrinfo *r;

	// Quick check of port
	if ( port < 1 || port > 65536 )
	{
		self->err = 2;
		err( 2, "die die die..." );
	}

	// Make a string out of number
	snprintf( portstr, 4, "%d", port );

	// Get smart about this and parse URIs to make this a little simpler to use
	// ...

	// Always get canoncial name information
	self->hints.ai_flags |= AI_CANONNAME;

	// Get address information
	if ( (stat = getaddrinfo( uri, portstr, &self->hints, &self->res)) != 0 )
	{
		self->err = errno;
		err(1, "%s", (char *)gai_strerror(stat));
	}

	// ...
	for ( r = self->res; r != NULL; r = self->res->ai_next ) 	
	{
		// I just want to see what's here...
		fprintf( stderr, "%d\n", r->ai_addrlen );
		fprintf( stderr, "%s\n", r->ai_canonname);

		// Bind to talk to the other guy
		if ((self->fd = socket( r->ai_family, r->ai_socktype, r->ai_protocol )) == -1)
		{
			fprintf( stderr, "socket connect error: %s\n", strerror( errno ) );
			continue; //try again
		}

		// Connect
		if (connect( self->fd, r->ai_addr, r->ai_addrlen) != -1)
			break;
		else 
		{
			fprintf( stderr, "socket connect error..." );
			err(1, "%s", strerror(errno));	
		}

		// Close the parent if unsuccessful
		if ( close( self->fd ) == -1 )
			err(1, "%s", strerror(errno));	
	}

	freeaddrinfo( self->res );	
	return 1;
}



//Send data via TCP Socket
_Bool socket_tcp_send (Socket *sock, uint8_t *msg, uint32_t length) 
{
	int bs  = 0;
	int t   = 0;
	int len = length;

	while ( len )
	{
		//Run
		if ( (bs = write(sock->fd, &msg[ t ], len)) == -1 )
			return 0;

		//This should keep running
		fprintf( stderr, "%d bytes written\n", bs );
		t   += bs;
		len -= t ;	
	}
	return 1;
}
#endif

#ifndef SINW_H


#endif
