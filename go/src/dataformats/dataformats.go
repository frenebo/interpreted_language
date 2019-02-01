package dataformats

// FormatType is a Data form enum
type FormatType int

const (
	// JSON format type contains a string consisting of json-encoded data
	JSON FormatType = iota
	// ErrorType format type is for errors in this code, should not be used in actual run time workspace
	ErrorType
	// PngImage format type is a binary png image
	PngImage
)
