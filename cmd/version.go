package cmd

import (
	"fmt"

	"github.com/spf13/cobra"
)

func init() {
	rootCmd.AddCommand(versionCmd)
}

var versionCmd = &cobra.Command{
	Use:   "version",
	Short: "Print the version number of hexline",
	Long:  `All software has versions. This is hexlines'`,
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("hexline 0.2")
	},
}
