package dataformats

// FormatType is a Data form enum
type FormatType int

const (
	// JSON format type contains a string consisting of json-encoded data
	JSON FormatType = iota
	ErrorType
)
