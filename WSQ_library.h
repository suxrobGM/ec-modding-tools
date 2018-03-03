#define WSQ_EXPORT __declspec( dllexport )


#if defined(__cplusplus)
extern "C" {
#endif

extern
int WSQ_EXPORT RegisterWSQ();


// Saves HBITMAP to an image file. Returns 1 if successfull, 0 otherwise 
extern
int WSQ_EXPORT SaveBMPToFile(HBITMAP hBitmap, const char *filename, int filetype);


// Creates an HBITMAP from an image file.  The extension of the file name
// determines the file type.  Returns an HBITMAP if successfull, NULL
// otherwise 
extern
HBITMAP WSQ_EXPORT CreateBMPFromFile(const char *filename);


// Creates an HBITMAP from WSQ compressed byte array.
// Returns an HBITMAP if successfull, NULL otherwise 
extern
HBITMAP WSQ_EXPORT CreateBMPFromWSQByteArray(unsigned char *input_wsq_byte_array, int size_of_input_wsq_byte_array);


// Saves WSQ compressed byte array to an image file.
// Returns 1 if successfull, 0 otherwise 
extern
int WSQ_EXPORT SaveWSQByteArrayToImageFile(unsigned char *input_wsq_byte_array, int size_of_input_wsq_byte_array, const char *filename, int filetype);


extern
int WSQ_EXPORT WSQ_decode_stream(unsigned char *input_data_stream, const int input_stream_length, unsigned char **output_data_stream, int *width, int *height, int *ppi, unsigned char **comment_text);


extern
int WSQ_EXPORT WSQ_encode_stream(unsigned char *input_data_stream, const int width, const int height, const double bitrate,
				   const int ppi, char *comment_text, unsigned char **output_data_stream, int *output_stream_length);

extern
void WSQ_EXPORT WriteWSQ_bitrate(double bitrate);


extern
double WSQ_EXPORT ReadWSQ_bitrate();


extern
void WSQ_EXPORT WriteWSQ_ppi(int ppi);


extern
int WSQ_EXPORT ReadWSQ_ppi();


extern
void WSQ_EXPORT WriteWSQ_comment(char *comment);


extern
char* WSQ_EXPORT ReadWSQ_comment();


extern
int WSQ_EXPORT ReadWSQ_implementation_number();


extern
int WSQ_EXPORT ReadTIFFcompression();


extern
void WSQ_EXPORT WriteTIFFcompression(int tiff_compression);


extern
int WSQ_EXPORT ReadTIFFpredictor();


extern
void WSQ_EXPORT WriteTIFFpredictor(int tiff_predictor);


extern
void WSQ_EXPORT ShowFileConverter();


extern
void WSQ_EXPORT SetShowFilePropertiesDialog(int file_properties_dialog);


extern
HBITMAP WSQ_EXPORT ConvertHBITMAPtoGrayScale256(HBITMAP hBitmap);


extern
int WSQ_EXPORT SaveHBITMAPtoFileAsGrayScale256BMP(HBITMAP hBitmap, const char *filename);



#if defined(__cplusplus)
 }
#endif
