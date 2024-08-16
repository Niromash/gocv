package main

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"
)

func addDLLExport(content string) string {
	re := regexp.MustCompile(`(?m)^\s*([^\s]+\s+[^\s]+\([^)]*\);)`)
	return re.ReplaceAllString(content, "DLL_EXPORT $1")
}

func processFile(path string) error {
	content, err := os.ReadFile(path)
	if err != nil {
		return err
	}

	updatedContent := addDLLExport(string(content))
	if err := os.WriteFile(path, []byte(updatedContent), 0644); err != nil {
		return err
	}

	fmt.Printf("File processed: %s\n", path)
	return nil
}

func processDirectory(root string) error {
	return filepath.Walk(root, func(path string, info os.FileInfo, err error) error {
		if err != nil {
			return err
		}

		if !info.IsDir() && strings.HasSuffix(info.Name(), ".h") {
			if err := processFile(path); err != nil {
				return err
			}
		}

		return nil
	})
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage: go run main.go <directory_path>")
		return
	}

	root := os.Args[1]
	if err := processDirectory(root); err != nil {
		fmt.Printf("Error processing directory: %v\n", err)
	} else {
		fmt.Println("Processing completed.")
	}
}
