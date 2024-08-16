package main

import (
	"fmt"
	"os"
	"path/filepath"
	"regexp"
	"strings"
)

func addDLLExport(content string) (string, bool) {
	// Expression régulière améliorée pour capturer les déclarations de fonction
	re := regexp.MustCompile(`(?m)^\s*(\w[\w\s\*]+?\s+\**\w+\([^)]*\)\s*;)`)
	updatedContent := re.ReplaceAllString(content, "DLL_EXPORT $1")
	return updatedContent, updatedContent != content
}

func getRelativeIncludePath(filePath string) string {
	depth := strings.Count(filepath.Dir(filePath), string(os.PathSeparator))
	relativePath := strings.Repeat("../", depth) + "mvsc.h"
	return relativePath
}

func addIncludeIfNecessary(content, filePath string) string {
	if !strings.Contains(content, `#include "mvsc.h"`) {
		includePath := getRelativeIncludePath(filePath)
		return fmt.Sprintf(`#include "%s"`+"\n\n%s", includePath, content)
	}
	return content
}

func processFile(path string) error {
	content, err := os.ReadFile(path)
	if err != nil {
		return err
	}

	updatedContent, modified := addDLLExport(string(content))
	if modified {
		updatedContent = addIncludeIfNecessary(updatedContent, path)
	}

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
